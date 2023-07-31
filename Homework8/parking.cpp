#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>

struct parkingg 
{
    std::string plate;
    int S_H;
    int S_M;
    int F_H;
    int F_M;
};

float get_parking_fee(float time_minutes, std::map<std::string, float>& prices);
int calculate_parking_time(struct parkingg data_array[]);
void load_parking_records(std::string parking, struct parkingg data_array[], int *repetitions);
void load_prices(std::string pricess, std::map<std::string, float>& prices);
float calculate_average_parking_fee(struct parkingg data_array[], std::map<std::string, float>& prices, int repetitions);
float calculate_average_parking_time(struct parkingg data_array[], int repetitions);
float calculate_average_stays (struct parkingg data_array[], int repetitions);
std::string get_most_common_region (struct parkingg data_array[], int repetitions);
int get_busiest_hour (struct parkingg data_array[], int repetitions);
int get_max_number_of_cars(struct parkingg data_array[], int repetitions);

int main() {

    std::map <std::string, float> prices;
    prices ["30m"];
    prices ["1h"];
    prices ["3h"];
    prices ["6h"];
    prices ["1d"];
    prices ["h+"];

    parkingg data_array[125];
    std::string parking = "parking_logs_01.csv";
    std::string pricess = "prices_01.txt";
    int repetitions = 0;

    load_parking_records(parking, data_array, &repetitions);

    // std::cout << data_array[0].plate << std::endl;
    // std::cout << data_array[0].S_H << std::endl;
    // std::cout << data_array[0].S_M << std::endl;
    // std::cout << data_array[0].F_H << std::endl;
    // std::cout << data_array[0].F_M << std::endl;

    load_prices(pricess, prices);
    // float time_minutes = calculate_parking_time(data_array);
    // std::cout << calculate_parking_time(data_array) << std::endl;
    // std::cout << get_parking_fee(380, prices) << std::endl;
    // std::cout << calculate_average_parking_time (data_array, repetitions)<< "\t" << calculate_average_parking_fee(data_array, prices, repetitions) << std::endl;
    // std::cout << calculate_average_stays(data_array, repetitions) << std::endl;
    // std::cout << get_most_common_region(data_array, repetitions) << std::endl;
    // std::cout << get_busiest_hour (data_array, repetitions) << std::endl;
    // std::cout << get_max_number_of_cars(data_array, repetitions) << std::endl;
    
    return 0;
}

void load_parking_records(std::string parking, struct parkingg data_array[], int *repetitions) {

    int f = 0;
    std::ifstream fin;
    std::string line;

    fin.open(parking);
    while (getline(fin, line)) { 
        (*repetitions)++;
        std::stringstream ss(line);
        std::string value;
        int i = 0;

        while (getline(ss, value, ',')) { 
            switch (i) {
                case 0:
                    data_array[f].plate = value;
                    break;
                case 1:
                    data_array[f].S_H = stoi(value);
                    break;
                case 2:
                    data_array[f].S_M = stoi(value);
                    break;
                case 3:
                    data_array[f].F_H = stoi(value);
                    break;
                case 4:
                    data_array[f].F_M = stoi(value);
                    break;
            }
            i++;
        }
        f++;
    }

}

void load_prices(std::string pricess, std::map<std::string, float>& prices) {
    std::ifstream fin;
    std::string line;
    int i = 0;
    fin.open("prices_01.txt");
    while (!fin.eof()) {
        getline(fin, line);
        // std::cout << line << std::endl;
        if (i == 0) {
            prices ["30m"] = stof(line.substr(line.find(" ") + 1));
            // std::cout << prices["30m"] << std::endl;
        } else if (i == 1) {
            prices ["1h"] = stof(line.substr(line.find(" ") + 1));
            // std::cout << prices["1h"] << std::endl;
        } else if (i == 2) {
            prices ["3h"] = stof(line.substr(line.find(" ") + 1));
            // std::cout << prices["3h"] << std::endl;
        } else if (i == 3) {
            prices ["6h"] = stof(line.substr(line.find(" ") + 1));
            // std::cout << prices["6h"] << std::endl;
        } else if (i == 4) {
            prices ["1d"] = stof(line.substr(line.find(" ") + 1));
            // std::cout << prices["1d"] << std::endl;
        } else if (i == 5) {
            prices ["h+"] = stof(line.substr(line.find(" ") + 1));
            // std::cout << prices["h+"] << std::endl;
        }
        i++;
    }
}

int calculate_parking_time(struct parkingg data_array[]) {
    int time;
    time = (data_array[0].F_H - data_array[0].S_H) * 60 + (data_array[0].F_M - data_array[0].S_M);
    return time;
}

float get_parking_fee(float time_minutes, std::map<std::string, float>& prices) {

    float hours;
    float fee;
    float money1;
    float money2;

    hours = time_minutes / 60;

    if (hours < 0.25) {
        return 0;
    } else if (hours > 0.25 && hours <= 0.5) {
        fee = prices["30h"];
        return fee;
    } else if (hours > 0.5 && hours < 1) {
        fee = prices["1h"];
        return fee;
    } else if (hours > 1 && hours <= 3) {
        money1 = prices["3h"];
        money2 = prices["1h"] + int(hours) * prices["h+"];
    } else if (hours > 3 && hours <= 6) {
        money1 = prices["6h"];
        money2 = prices["3h"] + int(hours - 2) * prices["h+"];
    } else if (hours > 6 && hours <= 12) {
        money1 = prices["1d"];
        money2 = prices["6h"] + int(hours - 5) * prices["h+"];
    } else if (hours > 12) {
        fee =  prices["12h"] + int(hours - 11) * prices["h+"];
        return fee;
    }




    if (money1 > money2) {
        fee = money2;
        return fee;
    } else {
        fee = money1;
        return fee;
    }

    
}

float calculate_average_parking_fee(struct parkingg data_array[], std::map<std::string, float>& prices, int repetitions) {
    int time;
    float hours;
    float fee;
    float money1;
    float money2;
    int count = 0;
    float total_fee = 0;
    float average_fee = 0;

    for (int i = 0; i < repetitions; i++) {
        time = (data_array[i].F_H - data_array[i].S_H) * 60 + (data_array[i].F_M - data_array[i].S_M);

        hours = time / 60;
        
        if (hours < 0.25) {
            return 0;
        } else if (hours > 0.25 && hours <= 0.5) {
            fee = prices["30h"];
            count = 1;
        } else if (hours > 0.5 && hours < 1) {
            fee = prices["1h"];
            count = 1;
        } else if (hours > 1 && hours <= 3) {
            money1 = prices["3h"];
            money2 = prices["1h"] + int(hours) * prices["h+"];
        } else if (hours > 3 && hours <= 6) {
            money1 = prices["6h"];
            money2 = prices["3h"] + int(hours - 2) * prices["h+"];
        } else if (hours > 6 && hours <= 12) {
            money1 = prices["1d"];
            money2 = prices["6h"] + int(hours - 5) * prices["h+"];
        } else if (hours > 12) {
            fee =  prices["12h"] + int(hours - 11) * prices["h+"];
            count = 1;
        }


        if (money1 > money2  && count != 1) {
            fee = money2;
        } else if (money1 < money2 && count != 1) {
            fee = money1;
        }

        count = 0;

        total_fee += fee;
    }

    return average_fee = total_fee / repetitions;

}

float calculate_average_parking_time(struct parkingg data_array[], int repetitions) {
    int time;
    float total_time = 0;
    for (int i = 0; i < repetitions; i++) {
        time = (data_array[i].F_H - data_array[i].S_H) * 60 + (data_array[i].F_M - data_array[i].S_M);
        total_time += time;
    }

    return total_time / float(repetitions);
}

float calculate_average_stays (struct parkingg data_array[], int repetitions) {
    float number_of_cars;
    std::map<std::string, int> same;
    for (int i = 0; i < repetitions; i++) {
        std::string element = data_array[i].plate;
        same[element]++;
    }

    for (const auto& pair : same) {
        if (pair.second >= 1) {
            number_of_cars++;
            std::cout << number_of_cars << std::endl;
        }
    }

    return float(repetitions) / number_of_cars;
}

std::string get_most_common_region (struct parkingg data_array[], int repetitions) {
    int number = 0;
    std::string country;
    std::map<std::string, int> same;
    for (int i = 0; i < repetitions; i++) {
        std::string element = data_array[i].plate;
        same[element]++;
    }

    for (const auto& pair : same) {
        if (pair.second > number) {
            number = pair.second;
            country = pair.first;
        }
    }

    return country.substr(0, 2);
}

int get_busiest_hour (struct parkingg data_array[], int repetitions) {
    int i = 0;
    int number = 0;
    int peak = 0;
    std::map<int, int> time;
    for (int i = 0; i < 25; i++) {
        time[i] = 0;
        for (int j = 0; j < repetitions; j++) {
            if (data_array[j].S_H <= i && i < data_array[j].F_H) {
                time[i]++;
            } 
        }
        // std::cout << i << "\t" << time[i] << std::endl;
    }

    for (const auto& timee : time) {
        if (timee.second > number) {
            number = timee.second;
            peak = timee.first;
        }
    }

    return peak;
}

int get_max_number_of_cars(struct parkingg data_array[], int repetitions) {

    int number = 0;
    int peak = 0;
    int time1 = 0;
    int time2 = 0;
    std::map<int, int> time_m;

    for (int i = 0; i < 1440; i++) {
        time_m[i] = 0;
    }

    for (int i = 0; i < repetitions; i++) {
        time1 = (data_array[i].S_H * 60) + data_array[i].S_M;
        time2 = (data_array[i].F_H * 60) + data_array[i].F_M;
        for (time1; time1 < time2; time1++) {
            time_m[time1]++;
        }
    }

    for (const auto& ti : time_m) {
        if (ti.second > number) {
            number = ti.second;
            peak = ti.first;
        }
    }

    for (const auto& ti : time_m) {
        std::cout << ti.first / 60 << ":" << ti.first % 60 << "--" << ti.second << std::endl;
    }



    return number;
}

