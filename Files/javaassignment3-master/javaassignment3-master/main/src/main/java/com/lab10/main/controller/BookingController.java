
package com.lab10.main.controller;

import com.lab10.main.model.Flight;
import com.lab10.main.model.FlightData;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.ResponseBody;

@Controller
public class BookingController {
    @Autowired
    FlightData flightData;

    @RequestMapping(value = "/bookings/reserve", method = RequestMethod.GET)
    public String reserveBooking(Model model) {
        model.addAttribute("flightList", flightData.GetAllFlights());
        return "bookings/reserveBooking";
    }

    @ResponseBody
    @RequestMapping(value = "/bookings/reserve", method = RequestMethod.POST)
    public String addBooking(@RequestParam String uuid, @RequestParam String people, Model model) {
        flightData.updatePeople(uuid, people);
        model.addAttribute("flightList", flightData.GetAllFlights());
        return "true";
    }

    @RequestMapping(value = "/bookings/cancel", method = RequestMethod.GET)
    public String cancelPage(Model model) {
        model.addAttribute("flightList", flightData.GetAllFlights());
        return "bookings/cancelBooking";
    }

    @RequestMapping(value = "/bookings/cancel", method = RequestMethod.POST)
    public String cancelBooking(@RequestParam String uuid, @RequestParam String people, Model model) {
        flightData.updatePeople(uuid, people);
        model.addAttribute("flightList", flightData.GetAllFlights());
        return "bookings/cancelBooking";
    }

}
