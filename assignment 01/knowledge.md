# Project knowledge

This file gives Codebuff context about your project: goals, commands, conventions, and gotchas.

## Quickstart
- Setup: C++20 compatible compiler + CMake 4.1+
- Build: `mkdir build && cd build && cmake .. && cmake --build .`
- Run: `./assignment_01` (Linux/Mac) or `assignment_01.exe` (Windows)

## Architecture
- Key directories: `src/` (12 header files with classes), `main.cpp` (entry point)
- Key classes: Engine, Insurance, Car, User, Admin, Seller, Buyer, Listing, Message, Marketplace, App, Menu
- Key relationships: Composition (Car→Engine, Car→Insurance), Aggregation (Listing→Seller, Buyer→Listing**), Inheritance (User→Admin/Seller/Buyer)

## Commands
- Build: `cmake --build .` (from build directory)
- Run: `./assignment_01` or `assignment_01.exe`
- Clean: Delete build directory and rebuild

## Conventions
- Header-only implementation (all classes in .h files)
- Manual memory management (no vectors, use new/delete)
- Deep copy semantics for all classes with dynamic allocation
- Const correctness (const data members, const member functions)
- Static members for global counters (User::userCount, Listing::listingCount)

## Test Accounts
- Admin: admin / admin123
- Seller: seller1 / pass123
- Buyer: buyer1 / pass789

## Things to avoid
- Using STL containers (vectors, lists, etc.) - required to use raw pointers
- Using .cpp files - header-only implementation required
- Shallow copies - always implement deep copy constructors and assignment operators
