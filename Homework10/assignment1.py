# Zadanie 1 - Parkujeme

# Meno: 
# Spolupráca: 
# Použité zdroje: 
# Čas potrebný na vypracovanie: 


def load_parking_records(file_path):  # 0.75b
    """
    Loads and returns parking records.
     - file_path: path to csv file with parking records
    Returns: list of tuples with number late, parking start hour and minute
             and parking end hour and minute.
    """
    
    try:
        file = open(file_path, 'r')
    except Exception:
        print('File does not exist')
        return
    li = list()
    while True:
        line = file.readline()
        if not line:
            break
        li.append(tuple(line.strip().split(',')))
    file.close()
    
    return list()


def load_prices(file_path):  # 0.75b
    """
    Loads and returns parking pricing.
     - file_path: path to txt file with prices
    Returns: dictionary with prices for 30m, 1h, 3h, 6h, 1d, h+
    """
    
    try:
        file = open(file_path, 'r')
    except Exception:
        print('File does not exist')
        return
    li = list()
    dic = dict()
    while True:
        line = file.readline()
        if not line:
            break
        li.append(tuple(line.strip().split(':')))
    file.close()
    
    for i, j in li:
        dic[i] = j.strip()
        
    print(dic)
    return dict()


def calculate_parking_time(start_h, start_m, end_h, end_m):  # 0.5b
    """
    Calculates and returns the duration of parking in minutes
    based on start and end time.
    """
    time = (end_h - start_h) * 60 + (end_m - start_m)
    
    return time
    return 0


def get_parking_fee(time_in_minutes, prices):  # 1b
    """
    Calculates and returns the price of parking for a given amount
    of time based on pricing.
    """

    hours = time_in_minutes / 60

    if (hours < 0.25):
        return 0
    elif (hours > 0.25 and hours <= 0.5):
        fee = prices["30h"]
        return fee
    elif (hours > 0.5 and hours < 1):
        fee = prices["1h"]
        return fee
    elif (hours > 1 and hours <= 3):
        money1 = prices["3h"]
        money2 = prices["1h"] + int(hours) * prices["h+"]
    elif (hours > 3 and hours <= 6):
        money1 = prices["6h"]
        money2 = prices["3h"] + int(hours - 2) * prices["h+"]
    elif (hours > 6 and hours <= 12):
        money1 = prices["1d"]
        money2 = prices["6h"] + int(hours - 5) * prices["h+"]
    elif (hours > 12):
        fee =  prices["12h"] + int(hours - 11) * prices["h+"]
        return fee
    




    if (money1 > money2):
        fee = money2
        return fee
    else:
        fee = money1
        return fee
    
    return 0.0


def calculate_average_parking_fee(records, prices):  # 0.5b
    """
    Calculates the average amount paid for parking during the day.
    """
    return 0.0


def calculate_average_parking_time(records):  # 0.5b
    """
    Calculates the average length of parking for the day.
    """
    return 0.0


def calculate_average_stays(records):  # 0.5b
    """
    Calculates the average number a car was parked during the day.
    """
    return 0.0


def get_most_common_region(records):  # 1b
    """
    Returns the code of the most common region of cars parked during the day.
    """
    return ""


def get_busiest_hour(records):  # 0.5b
    """
    Returns the hour when the most cars were parked at the parking lot.
    It considers cars that were parked before or at the given hour
    and stayed at the parking lot until or after the given hour.
    """
    return 0


def get_max_number_of_cars(records):  # 2b
    """
    Returns the highest number of cars parked at the parking lot in a given
    minute.
    """
    return 0, list()


def optimize_hourly_fee(records, prices):  # 2b
    """
    Returns the fee of additional hours that will maximize income for
    the parking lot.
    """
    return 0.0
