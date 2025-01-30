package com.reservas.vuelos.model;

import com.reservas.vuelos.service.Reserva;

public class ticket {
    private int id;

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }
    private Reserva reserva;
    private String codigoTicket;

    public Reserva getReserva() {
        return reserva;
    }

    public void setReserva(Reserva reserva) {
        this.reserva = reserva;
    }

    public String getCodigoTicket() {
        return codigoTicket;
    }

    public void setCodigoTicket(String codigoTicket) {
        this.codigoTicket = codigoTicket;
    }

    // Constructor, getters y setters
}