package com.lab10.main.model;

import java.util.UUID;

import lombok.Data;

/**
 * Flight
 */
@Data
public class Flight {
    public UUID id = UUID.randomUUID();
    public String people;
    public String destination;
    public String origin;
    public String date;
    public String time;
    public boolean isCanceled = false;
    public String cancelReason = "";

    /**
     * Add new flight
     * 
     * @param amtOfPeople
     * @param destination
     * @param origin
     * @param date
     * @param time
     */
    public Flight(String amtOfPeople, String destination, String origin, String date, String time) {
        this.setPeople(amtOfPeople);
        this.setDestination(destination);
        this.setOrigin(origin);
        this.setDate(date);
        this.setTime(time);
    }

    public Flight() {

    }

    public String getPeople() {
        return people;
    }

    public void setPeople(String people) {
        this.people = people;
    }

    public String getDestination() {
        return destination;
    }

    public void setDestination(String destination) {
        this.destination = destination;
    }

    public String getOrigin() {
        return origin;
    }

    public void setOrigin(String origin) {
        this.origin = origin;
    }

    public String getTime() {
        return time;
    }

    public void setTime(String time) {
        this.time = time;
    }

    public UUID getId() {
        return id;
    }

    public void setId(UUID id) {
        this.id = id;
    }

    public String getDate() {
        return date;
    }

    public void setDate(String date) {
        this.date = date;
    }

    public boolean isCanceled() {
        return isCanceled;
    }

    public void setCanceled(boolean isCanceled) {
        this.isCanceled = isCanceled;
    }

    public String getCancelReason() {
        return cancelReason;
    }

    public void setCancelReason(String cancelReason) {
        this.cancelReason = cancelReason;
    }
}