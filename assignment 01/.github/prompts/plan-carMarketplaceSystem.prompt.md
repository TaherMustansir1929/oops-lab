## Plan: Car Marketplace System (PakWheels-style)

**TL;DR**: Build a C++ TUI Car Marketplace with 12 classes split across header files in `src/`, driven by a single `main.cpp`. The system supports three user roles (Admin, Seller, Buyer) with authentication, listing CRUD, search/filter, favorites, and messaging. All dynamic arrays use `new`/`delete` (no vectors). The architecture demonstrates inheritance, polymorphism, composition, aggregation, static members, constants, constructors, and array-of-objects — all assignment requirements.

**Steps**

1. **Create `src/Engine.h`** — Engine class (composition target for Car)
   - Data (6): `type`, `horsepower`, `displacement`, `fuelType`, `cylinders`, `transmissionType`
   - Functions (4+): `display() const`, `isHighPerformance()`, `getFuelEfficiencyRating()`, `compareWith(const Engine&)`
   - Constructors: default, parameterized, copy

2. **Create `src/Insurance.h`** — Insurance class (2nd composition target for Car)
   - Data (6): `policyNumber` (**const**), `provider`, `coverageType`, `premium`, `expiryDate`, `isActive`
   - Functions (4+): `display() const`, `isExpired()`, `renew()`, `calculatePremium()`
   - Constructors: default, parameterized, copy

3. **Create `src/Car.h`** — Car class
   - Data (8): `brand`, `model`, `year`, `price`, `mileage`, `color`, `Engine engine` (**composition #1**), `Insurance insurance` (**composition #2**)
   - Functions (4+): `display() const`, `matchesFilter()`, `calculateDepreciation()`, `compareTo(const Car&)`
   - Constructors: default, parameterized, copy

4. **Create `src/User.h`** — Base class for all users
   - Data (6): `userId` (**const**), `username`, `password`, `email`, `phone`, `isActive`
   - **Static**: `static int userCount` + `static int getUserCount()` — tracks total users created
   - Functions (4+): `virtual display() const`, `authenticate()`, `updateProfile()`, `virtual getRole() const` (pure virtual for polymorphism)
   - Constructors: default, parameterized, copy; virtual destructor

5. **Create `src/Admin.h`** — Inherits User
   - Data (5): `adminLevel`, `department`, `accessCode`, `lastLogin`, `approvedCount`
   - Functions (4+): `approveListing()`, `removeListing()`, `viewAllListings()`, `viewAllUsers()`, `getRole() const override`

6. **Create `src/Seller.h`** — Inherits User
   - Data (5): `shopName`, `rating`, `totalSales`, `address`, `sellerSince`
   - Functions (4+): `createListing()`, `updateListing()`, `deleteListing()`, `viewMyListings()`, `getRole() const override`

7. **Create `src/Buyer.h`** — Inherits User
   - Data (5): `Listing** favorites` (**aggregation #2** — pointers to existing Listings), `favoriteCount`, `maxFavorites`, `budget`, `preferredBrand`
   - Functions (4+): `addFavorite()`, `removeFavorite()`, `viewFavorites()`, `sendMessage()`, `getRole() const override`
   - Destructor: `delete[] favorites` (pointer array only, not the pointed-to objects)

8. **Create `src/Listing.h`** — Listing/Ad class
   - Data (7): `listingId` (**const**), `Car car` (composition of Car, which itself composes Engine+Insurance), `Seller* seller` (**aggregation #1** — pointer to external Seller), `title`, `description`, `isApproved`, `datePosted`
   - **Static**: `static int listingCount` + `static int getListingCount()`
   - Functions (4+): `display() const`, `approve()`, `reject()`, `updateDetails()`
   - Constructors: default, parameterized, copy

9. **Create `src/Message.h`** — Messaging between Buyer and Seller
   - Data (6): `messageId`, `senderName`, `receiverName`, `content`, `timestamp`, `isRead`
   - Functions (4+): `display() const`, `markAsRead()`, `formatMessage()`, `isFromUser()`
   - Constructors: default, parameterized, copy

10. **Create `src/Marketplace.h`** — Manages listings, messages, search
    - Data (7): `Listing** listings`, `listingCount`, `listingCapacity`, `Message** messages`, `messageCount`, `messageCapacity`, `name` (**const**)
    - Functions (5+): `addListing()`, `removeListing()`, `searchByBrand()`, `searchByPriceRange()`, `filterByYear()`, `displayAllListings()`, `addMessage()`, `getMessagesForUser()`
    - **Array of objects**: `Listing**` and `Message**` managed with `new`/`delete` + capacity resizing
    - Destructor: cleans up all DMA

11. **Create `src/Menu.h`** — TUI flow controller
    - Data (5): `currentUserType`, `currentUserIndex`, `isRunning`, `menuTitle`, `App* app`
    - Functions (5+): `showWelcome()`, `handleAuth()`, `showAdminMenu()`, `showSellerMenu()`, `showBuyerMenu()`
    - Delegates all data operations to App/Marketplace

12. **Create `src/App.h`** — Application entry point, owns all global data
    - Data (6): `Marketplace marketplace`, `User** users`, `userCount`, `userCapacity`, `appName` (**const**), `isInitialized`
    - Functions (5+): `run()`, `initialize()`, `cleanup()`, `registerUser()`, `findUserByUsername()`, `loginUser()`
    - **Array of objects**: `User**` — polymorphic array holding Admin*/Seller*/Buyer*
    - Destructor: cleans up all DMA

13. **Update `main.cpp`** — Instantiate `App`, call `app.run()`, which starts `Menu` loop

14. **Update `CMakeLists.txt`** — Add `src/` to include directories

15. **Create `README.md`** — Document every requirement with file/line references:
    - Table mapping each requirement to specific code locations
    - Explain composition (Car↔Engine, Car↔Insurance), aggregation (Listing→Seller*, Buyer→favorites)
    - Explain static members and why they're static
    - Explain const usage (5 const data members, const pointer, const functions)
    - Explain constructors used and why
    - List all 12 classes with their member counts

**Key Design Decisions**

- **Composition**: `Car` embeds `Engine` and `Insurance` as value members (not pointers). When `Car` is destroyed, they're destroyed too.
- **Aggregation**: `Listing` holds `Seller*` (pointer, doesn't own Seller). `Buyer` holds `Listing**` favorites (pointers to Marketplace-owned listings).
- **Polymorphism**: `User` has `virtual getRole()` and `virtual display()`. `App` stores `User**` array, casts to subtype as needed.
- **DMA resize**: Helper function `resizeArray<T>(T**& arr, int& capacity)` — allocates double capacity, copies pointers, deletes old array.
- **const pointer**: `const Seller*` in Listing (seller of a listing can't be reassigned)
- **Authentication**: Simple username/password match against stored users. Role determined by `getRole()`.
- **No vectors**: All arrays are raw `T**` with manual `new`/`delete` and capacity tracking.

**Verification**
- Build with CMake: `cmake --build build/` — must compile with zero errors
- Run the executable, test: register Admin/Seller/Buyer → login → perform role actions (add listing, approve, search, favorite, message)
- Verify DMA: no memory leaks in destructor chains (manual check)

**Decisions**
- Chose embedded objects for composition over pointer-with-ownership to make the relationship visually clear
- Chose `User**` (pointer array) over `User*` (object array) to support polymorphism with inheritance
- Chose header-only implementation (no `.cpp` files) per user request for simplicity
- 12 classes total, exceeding the 10-class minimum
