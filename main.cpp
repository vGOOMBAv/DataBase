#include <map>
#include <vector>
#include <set>
#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;

class Date {
public:
    Date(int y, int m, int d) {
        year = y;
        month = m;
        day = d;
    }
    int GetYear() const {
        return year;
    }
    int GetMonth() const {
        return month;              
    }
    int GetDay() const {
        return day;
    }
private:
    int year, month, day;
};


class Database {
public:
    void AddEvent(const Date& date, const string& event) {
        events[date].insert(event);
    }
    void DeleteEvent(const Date& date, const string& event) {//bool
        bool is_found = false;
        try {
            set<string> test_set = events.at(date);
            for (const auto& i : events[date]) {
                if (i == event) {
                    is_found = true;
                    break;
                }
            }
        }
        catch (const out_of_range&) {}
        if (is_found == true) {
            events[date].erase(event);
            cout << "Deleted successfully" << endl;
            if (events[date].size() == 0)events.erase(date);
        }
        else {
            cout << "Event not found" << endl;
        }
    }
    void DeleteDate(const Date& date) {//int
        bool is_found = false;
        try {
            set<string> test_set = events.at(date);
            is_found = true;
        }
        catch (const out_of_range&) {}
        if (is_found == true) {
            cout << "Deleted " << events[date].size() << " events" << endl;
            events[date].clear();
            events.erase(date);
        }
        else {
            cout << "Deleted 0 events" << endl;
        }
    }

    void Find(const Date& date) const {
        bool is_found;
        try {
            set<string> buff_set = events.at(date);
            is_found = true;
        }
        catch (const out_of_range&) {
            is_found = false;
        }
        if (is_found == false) {
            
        }
        else {
            string events_str;
            for (const auto& i : events.at(date)) {
                cout << i << endl;
            }
        }
    }

    void Print() const {
        for (const auto& i : events) {
            for (const auto& j : i.second) {
                cout << setfill('0') << setw(4) << i.first.GetYear() << '-' << setw(2) << i.first.GetMonth() << '-' << setw(2) << i.first.GetDay() << right << " " << j << endl;
            }
       }
    }
private:
    map<Date, set<string>> events;
};

Date DateConstruct(int y, int m, int d);//Throws in case of wrong data values and returns constructed Date class
bool operator<(const Date& lhs, const Date& rhs);
void OptionCheck(const string&);//Throws exceptions in case of wrong option;
void DateCheck(string date);//Throws exceptions in case of wrong data format;

int main() {
    Database db;
    string command;

    while (getline(cin, command)) {
        stringstream ss;
        ss << command;
        string option;
        ss >> option;
        if (option.size() != 0) {
            try {
                OptionCheck(option);
                if (option == "Print") {
                    db.Print();
                }
                else {
                    int year, month, day;
                    string date;
                    ss >> date;
                    DateCheck(date);
                    stringstream date_stringstream;
                    date_stringstream << date;
                    date_stringstream >> year;
                    date_stringstream.ignore(1);
                    date_stringstream >> month;
                    date_stringstream.ignore(1);
                    date_stringstream >> day;
                    Date entered_date = DateConstruct(year, month, day);
                    if (option == "Add") {
                        string event;
                        ss >> event;
                        db.AddEvent(entered_date, event);
                    }
                    else if (option == "Del") {
                        string event;
                        ss >> event;
                        if (event.size() == 0) {
                            db.DeleteDate(entered_date);
                        }
                        else {
                            db.DeleteEvent(entered_date, event);
                        }
                    }
                    else if (option == "Find") {
                        db.Find(entered_date);
                    }
                }

            }
            catch (const runtime_error & re) {
                cout << re.what() << endl;
                return 0;
            }
        }
    }

    return 0;
}

bool operator<(const Date& lhs, const Date& rhs) {
    if (lhs.GetYear() < rhs.GetYear()) {
        return true;
    }
    else if (lhs.GetYear() > rhs.GetYear()) {
        return false;
    }
    else {
        if (lhs.GetMonth() < rhs.GetMonth()) {
            return true;
        }
        else if (lhs.GetMonth() > rhs.GetMonth()) {
            return false;
        }
        else {
            if (lhs.GetDay() < rhs.GetDay()) {
                return true;
            }
            else {
                return false;
            }
        }
    }
}

Date DateConstruct(int year, int month, int day) {
    if (month < 1 || month>12) {
        throw runtime_error("Month value is invalid: " + to_string(month));
    }
    if (day < 1 || day>31) {
        throw runtime_error("Day value is invalid: " + to_string(day));
    }

    return Date{ year,month,day };
}

void OptionCheck(const string& s) {
    if (s != "Add" && s != "Del" && s != "Find" && s != "Print") {
        throw runtime_error("Unknown command: " + s);
    }
}
void DateCheck(string date) {
    stringstream ss;
    string buff_date;
    ss << date;
    int year, month;
    ss >> year;
    ss >> buff_date;
    if (buff_date[0] != '-') {
        throw runtime_error("Wrong date format: " + date);
        return;
    }
    if ((int)buff_date[1]<(int)'0' || (int)buff_date[1] > (int)'9') {
        if (buff_date[1] != '+' && buff_date[1] != '-') {
            throw runtime_error("Wrong date format: " + date);
            return;
        }
        else {
            if ((int)buff_date[2]<(int)'0' || (int)buff_date[1] > (int)'9') {
                throw runtime_error("Wrong date format: " + date);
                return;
            }
        }
    }
    stringstream ss2;
    ss2 << buff_date;
    buff_date.clear();
    ss2.ignore(1);
    ss2 >> month;
    ss2 >> buff_date;
    if (buff_date.size() == 1)throw runtime_error("Wrong date format: " + date);
    if (buff_date[0] != '-') {
        throw runtime_error("Wrong date format: " + date);
        return;
    }
    if ((int)buff_date[1]<(int)'0' || (int)buff_date[1] > (int)'9') {
        if (buff_date[1] != '+' && buff_date[1] != '-') {
            throw runtime_error("Wrong date format: " + date);
            return;
        }
        else {
            if (buff_date.size() > 2) {
                if ((int)buff_date[2]<(int)'0' || (int)buff_date[1] > (int)'9') {
                    throw runtime_error("Wrong date format: " + date);
                    return;
                }
            }
            else {
                throw runtime_error("Wrong date format: " + date);
                return;
            }
        }
    }
    stringstream ss3;
    int day_string;
    ss3 << buff_date;
    char check;
    ss3 >> check;
    if (check != '-')throw runtime_error("Wrong date format: " + date);
    ss3 >> day_string;
    buff_date.clear();
    ss3 >> buff_date;
    if (buff_date.size() != 0)throw runtime_error("Wrong date format: " + date);

}
