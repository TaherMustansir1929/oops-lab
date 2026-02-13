#ifndef MESSAGE_H
#define MESSAGE_H

#include <iostream>
#include <cstring>

class Message {
private:
    int messageId;
    char* senderName;
    char* receiverName;
    char* content;
    char* timestamp;
    bool isRead;

    void copyString(char*& dest, const char* src) {
        if (src) {
            dest = new char[strlen(src) + 1];
            strcpy(dest, src);
        } else {
            dest = nullptr;
        }
    }

    void deleteString(char*& str) {
        if (str) {
            delete[] str;
            str = nullptr;
        }
    }

    static int nextMessageId;  // For auto-incrementing message IDs

public:
    // Default Constructor
    Message() : messageId(++nextMessageId), senderName(nullptr), 
                receiverName(nullptr), content(nullptr), 
                timestamp(nullptr), isRead(false) {
        copyString(senderName, "Unknown");
        copyString(receiverName, "Unknown");
        copyString(content, "No content");
        copyString(timestamp, "00:00:00");
    }

    // Parameterized Constructor
    Message(const char* sender, const char* receiver, const char* cont, 
            const char* time)
        : messageId(++nextMessageId), isRead(false) {
        copyString(senderName, sender);
        copyString(receiverName, receiver);
        copyString(content, cont);
        copyString(timestamp, time);
    }

    // Copy Constructor
    Message(const Message& other)
        : messageId(other.messageId), isRead(other.isRead) {
        copyString(senderName, other.senderName);
        copyString(receiverName, other.receiverName);
        copyString(content, other.content);
        copyString(timestamp, other.timestamp);
    }

    // Destructor
    ~Message() {
        deleteString(senderName);
        deleteString(receiverName);
        deleteString(content);
        deleteString(timestamp);
    }

    // Assignment Operator
    Message& operator=(const Message& other) {
        if (this != &other) {
            deleteString(senderName);
            deleteString(receiverName);
            deleteString(content);
            deleteString(timestamp);
            
            messageId = other.messageId;
            copyString(senderName, other.senderName);
            copyString(receiverName, other.receiverName);
            copyString(content, other.content);
            copyString(timestamp, other.timestamp);
            isRead = other.isRead;
        }
        return *this;
    }

    // Display message details (const function)
    void display() const {
        std::cout << "\n--- Message #" << messageId << " ---\n";
        std::cout << "From: " << (senderName ? senderName : "N/A") << "\n";
        std::cout << "To: " << (receiverName ? receiverName : "N/A") << "\n";
        std::cout << "Time: " << (timestamp ? timestamp : "N/A") << "\n";
        std::cout << "Status: " << (isRead ? "Read" : "Unread") << "\n";
        std::cout << "Content: " << (content ? content : "N/A") << "\n";
        std::cout << "---------------------------\n";
    }

    // Mark message as read
    void markAsRead() {
        if (!isRead) {
            isRead = true;
            std::cout << "Message #" << messageId << " marked as read.\n";
        }
    }

    // Format message for display (const function)
    void formatMessage() const {
        std::cout << "[" << (timestamp ? timestamp : "N/A") << "] ";
        std::cout << (senderName ? senderName : "N/A") << " -> ";
        std::cout << (receiverName ? receiverName : "N/A") << ": ";
        std::cout << (content ? content : "N/A");
        std::cout << (isRead ? " [Read]" : " [Unread]") << "\n";
    }

    // Check if message is from a specific user (const function)
    bool isFromUser(const char* username) const {
        if (!username || !senderName) return false;
        return strcmp(senderName, username) == 0;
    }

    // Getters
    int getMessageId() const { return messageId; }
    const char* getSenderName() const { return senderName; }
    const char* getReceiverName() const { return receiverName; }
    const char* getContent() const { return content; }
    const char* getTimestamp() const { return timestamp; }
    bool getIsRead() const { return isRead; }

    // Setters
    void setSenderName(const char* sender) {
        deleteString(senderName);
        copyString(senderName, sender);
    }
    void setReceiverName(const char* receiver) {
        deleteString(receiverName);
        copyString(receiverName, receiver);
    }
    void setContent(const char* cont) {
        deleteString(content);
        copyString(content, cont);
    }
    void setTimestamp(const char* time) {
        deleteString(timestamp);
        copyString(timestamp, time);
    }
    void setIsRead(bool read) { isRead = read; }
};

// Initialize static member
int Message::nextMessageId = 0;

#endif // MESSAGE_H
