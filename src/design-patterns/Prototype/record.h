/***************************************************************************
 *
 * Copyright © 2016 LT. All Rights Reserved.
 *
 ***************************************************************************/

/**
 *
 * @file: record.h
 *
 * @breaf: 
 *
 * @author: Lei Yunfei(towardstheway@gmail.com)
 *
 * @create: 2018/03/14 18时12分16秒
 *
 **/


#ifndef  RECORD_INC
#define  RECORD_INC

#include <iostream>
#include <memory>
#include <string>
#include <unordered_map>

class Record {
public:
    Record() {}
    virtual ~Record() {}
    virtual void print() = 0;
    virtual std::unique_ptr<Record> clone() = 0;
};


class CarRecord : public Record {
public:
    CarRecord(std::string name, int id) : car_name_(name), id_(id) {}
    ~CarRecord() {}

    void print() override {
        std::cout << "Car Record" << std::endl
                  << "Name: " << car_name_ << std::endl
                  << "Number: " << id_ << std::endl << std::endl;
    }

    std::unique_ptr<Record> clone() override {
        return std::make_unique<CarRecord>(*this);
    }

private:
    std::string car_name_;
    int id_;
};


class BikeRecord : public Record {
public:
    BikeRecord(std::string name, int number) : bike_name_(name), id_(number) {}
    virtual ~BikeRecord() {}

    void print() override {
        std::cout << "Bike Record" << std::endl
                  << "Name: " << bike_name_ << std::endl
                  << "Number: " << id_ << std::endl << std::endl;;
    }

    std::unique_ptr<Record> clone() override {
        return std::make_unique<BikeRecord>(*this);
    }

private:
    std::string bike_name_;
    int id_;
};


class PersonRecord : public Record {
public:
    PersonRecord(std::string name, int number) : person_name_(name), id_(number) {}
    virtual ~PersonRecord() {}

    void print() override {
        std::cout << "Person Record" << std::endl
                  << "Name: " << person_name_ << std::endl
                  << "Number: " << id_ << std::endl << std::endl;
    }

    std::unique_ptr<Record> clone() override {
        return std::make_unique<PersonRecord>(*this);
    }

private:
    std::string person_name_;
    int id_;
};


enum RecordType {
    CAR,
    BIKE,
    PERSON
};

class RecordFactory {
public:
    RecordFactory() {
        records_[CAR] = std::make_unique<CarRecord>("Feffari", 5050);
        records_[BIKE] = std::make_unique<BikeRecord>("Yamaha", 2525);
        records_[PERSON] = std::make_unique<PersonRecord>("Tom", 125);
    }

    std::unique_ptr<Record> CreateRecord(RecordType record_type) {
        return records_[record_type]->clone();
    }

private:
    std::unordered_map<RecordType, std::unique_ptr<Record>, std::hash<int>> records_;
};


class PrototypeMonster {
public:
    PrototypeMonster() {}
    PrototypeMonster(const PrototypeMonster &copy) {
        name_ = copy.name_;
    }
    virtual ~PrototypeMonster() {}

    virtual PrototypeMonster *Clone() const = 0;

    void set_name(std::string name) {
        name_ = name;
    }
    std::string get_name() const {
        return name_;
    }

protected:
    std::string name_;
};


class GreenMonster : public PrototypeMonster {
public:
    GreenMonster() {}
    GreenMonster(const GreenMonster &copy) {}
    ~GreenMonster() {}

    virtual PrototypeMonster *Clone() const {
        return new GreenMonster(*this);
    }

    void set_num_of_arms(int number) {
        number_of_arms_ = number;
    }
    int get_num_of_arms() const {
        return number_of_arms_;
    }

    void set_slime_available(double slime) {
        slime_available_ = slime;
    }
    double get_slime_available() const {
        return slime_available_;
    }

protected:
    int number_of_arms_;
    double slime_available_;
};


class PurpleMonster : public PrototypeMonster {
public:
    PurpleMonster() {}
    PurpleMonster(const PurpleMonster &copy) {
        intensity_of_bad_breath_ = copy.intensity_of_bad_breath_;
        length_of_whiplike_antenna_ = copy.length_of_whiplike_antenna_;
    }
    virtual ~PurpleMonster() {}

    virtual PrototypeMonster *Clone() const {
        return new PurpleMonster(*this);
    }

    void set_intensity_of_bad_breath(int intensity_of_bad_breath) {
        intensity_of_bad_breath_ = intensity_of_bad_breath;
    }
    int get_intensity_of_bad_breath() const {
        return intensity_of_bad_breath_;
    }

    void set_length_of_whiplike_antenna(double length) {
        length_of_whiplike_antenna_ = length;
    }
    double get_length_of_whiplike_antenna() const {
        return length_of_whiplike_antenna_;
    }

protected:
    int intensity_of_bad_breath_;
    double length_of_whiplike_antenna_;
};


class BellyMonster : public PrototypeMonster {
public:
    BellyMonster() {}
    BellyMonster(const BellyMonster &copy) {
        room_available_in_belly_ = copy.room_available_in_belly_;
    }
    virtual ~BellyMonster() {}

    virtual PrototypeMonster *Clone() const {
        return new BellyMonster(*this);
    }

    void set_room_available_in_belly(double room_available) {
        room_available_in_belly_ = room_available;
    }
    double get_room_available_in_belly() const {
        return room_available_in_belly_;
    }

protected:
    double room_available_in_belly_;
};


#endif   // ----- #ifndef RECORD_INC  -----
