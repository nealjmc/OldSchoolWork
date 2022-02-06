package com.lab10.main.model;

import java.util.ArrayList;
import java.util.UUID;

import org.springframework.stereotype.Service;

/**
 * FlightData
 */
@Service
public class FlightData {

    ArrayList<Flight> flightList = new ArrayList<Flight>();

    public void AddFlight(Flight newFlight) {
        flightList.add(newFlight);
    }

    public ArrayList<Flight> GetAllFlights() {
        return flightList;
    }

    public Flight GetFlightByUid(String uid) {
        Flight flightToReturn = new Flight();
        for (Flight flight : flightList) {
            if (flight.id == UUID.fromString(uid)) {
                flightToReturn = flight;
            }
        }
        return flightToReturn;
    }

    public void cancelFlight(String uid, String cancelReason) {
        UUID parsedId = UUID.fromString(uid);
        for (int i = 0; i < flightList.size(); i++) {
            if (flightList.get(i).id.equals(parsedId)) {
                Flight newFlight = flightList.get(i);
                newFlight.setCancelReason(cancelReason);
                newFlight.setCanceled(true);
                flightList.set(i, newFlight);
            }
        }
    }

    public void updatePeople(String uid, String people) {
        UUID parsedId = UUID.fromString(uid);
        for (int i = 0; i < flightList.size(); i++) {
            if (flightList.get(i).id.equals(parsedId)) {
                Flight newFlight = flightList.get(i);
                newFlight.setPeople(people);
                flightList.set(i, newFlight);
            }
        }
    }
}