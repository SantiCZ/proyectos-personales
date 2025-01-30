package com.reservas.vuelos.service;

public class Vuelo {

    private int id;

    private String origen;

    private String destino;

    private String fecha;

    private int capacidad;



    public Vuelo(int id, String origen, String destino, String fecha, int capacidad) {

        this.id = id;

        this.origen = origen;

        this.destino = destino;

        this.fecha = fecha;

        this.capacidad = capacidad;

    }
    public String getOrigen() {
        return origen;
    }

    public String getDestino() {
        return destino;
    }

    public String getFecha() {
        return fecha;
    }

    public int getId() {
        return id;
    }

    public int getCapacidad() {
        return capacidad;
    }
    public int getAsientosDisponibles() {
        // TODO Auto-generated method stub
        throw new UnsupportedOperationException("Unimplemented method 'getAsientosDisponibles'");
    }
    public void setAsientosDisponibles(int i) {
        // TODO Auto-generated method stub
        throw new UnsupportedOperationException("Unimplemented method 'setAsientosDisponibles'");
    }

    // existing fields and methods

}
