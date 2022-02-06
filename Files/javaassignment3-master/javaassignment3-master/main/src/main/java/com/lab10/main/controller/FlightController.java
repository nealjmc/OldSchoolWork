
package com.lab10.main.controller;

import com.lab10.main.model.Flight;
import com.lab10.main.model.FlightData;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.ModelAttribute;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.ResponseBody;

@Controller
public class FlightController {
    @Autowired
    FlightData flightData;

    @RequestMapping(value = "flights/show", method = RequestMethod.GET)
    public String showFlights(Model model) {
        model.addAttribute("flightList", flightData.GetAllFlights());

        return "flights/showFlights";
    }

    @RequestMapping(value = "/flights/cancel", method = RequestMethod.GET)
    public String cancelFlights(Model model) {
        model.addAttribute("flightList", flightData.GetAllFlights());

        return "flights/cancelFlights";
    }

    @RequestMapping(value = "/flights/schedule", method = RequestMethod.GET)
    public String scheduleFlights(Model model) {
        model.addAttribute("flightList", flightData.GetAllFlights());
        return "flights/scheduleFlights";
    }

    @RequestMapping(value = "/flights/schedule", method = RequestMethod.POST)
    public String saveScheduleFlight(@ModelAttribute Flight newFlight, Model model) {

        flightData.AddFlight(newFlight);
        model.addAttribute("flightList", flightData.GetAllFlights());
        return "flights/showFlights";
    }

    @ResponseBody
    @RequestMapping(value = "/flights/cancel", method = RequestMethod.POST)
    public String saveScheduleFlight(@RequestParam String uid, @RequestParam String cancelReason, Model model) {

        flightData.cancelFlight(uid, cancelReason);
        model.addAttribute("flightList", flightData.GetAllFlights());
        return String.valueOf(flightData.GetFlightByUid(uid).isCanceled);
    }

}