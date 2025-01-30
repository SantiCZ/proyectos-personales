package com.reservas.vuelos.model;

import com.reservas.vuelos.service.Usuario;
import com.reservas.vuelos.service.Vuelo;

public class reserva {
    private int id;
    private Usuario usuario;
    private Vuelo vuelo;
    private String fechaReserva;

    // Constructor, getters y setters
    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public Usuario getUsuario() {
        return usuario;
    }

    public void setUsuario(Usuario usuario) {
        this.usuario = usuario;
    }

    public Vuelo getVuelo() {
        return vuelo;
    }

    public void setVuelo(Vuelo vuelo) {
        this.vuelo = vuelo;
    }

    public String getFechaReserva() {
        return fechaReserva;
    }

    public void setFechaReserva(String fechaReserva) {
        this.fechaReserva = fechaReserva;
    }
}