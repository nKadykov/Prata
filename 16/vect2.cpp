#include <iostream>
#include <string>
#include <vector>

struct Review {
    std::string title;
    int rating;
};

bool fillReview(Review &rr);
void showReview(const Review &rr);

int main() {
    using std::cout;
    using std::vector;
    vector<Review> books;
    Review temp;
    while(fillReview(temp)) {
        books.push_back(temp);
    }
    int num = books.size();
    if(num > 0) {
        cout << "Thank you. You entered the following:\nRating\tBook\n";
        for(int i = 0; i < num; i++) {
            showReview(books[i]);
        }
        cout << "Reprising:\nRating\tBook\n";
        vector<Review>::iterator pr;
        for(pr = books.begin(); pr != books.end(); pr++) {
            showReview(*pr);
        }
        vector<Review> oldlist(books);
        if(num > 3) {
            books.erase(books.begin() + 1, books.begin() + 3);
            cout << "After erasure:\n";
            for(pr = books.begin(); pr != books.end(); pr++) {
                showReview(*pr);
            }
            books.insert(books.begin(), oldlist.begin() + 1, oldlist.begin() + 2);
            cout << "After insertion:\n";
            for(pr = books.begin(); pr != books.end(); pr++) {
                showReview(*pr);
            }
        }
        books.swap(oldlist);
        cout << "Swapping oldlist with books:\n";
        for(pr = books.begin(); pr != books.end(); pr++) {
            showReview(*pr);
        }
    }
    else {
        cout << "Nothing entered, nothing gained.\n";
    }
    return 0;
}

bool fillReview(Review &rr) {
    std::cout << "Enter book title (quit to quit): ";
    std::getline(std::cin, rr.title);
    if(rr.title == "quit") {
        return false;
    }
    std::cout << "Enter book rating: ";
    std::cin >> rr.rating;
    if(!std::cin) {
        return false;
    }
    while(std::cin.get() != '\n') {
        continue;
    }
    return true;
}

void showReview(const Review &rr) {
    std::cout << rr.rating << "\t" << rr.title << std::endl;
}