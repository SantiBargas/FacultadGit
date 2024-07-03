package ParcialObjetos;

import java.util.Vector;

public class ComedorDTO {

	private String descripcion;
	private String domicilio;
	private Vector<Entrega>myEntrega;
	
	public ComedorDTO(String descripcion, String domicilio, Vector<Entrega> myEntrega) {
		super();
		this.descripcion = descripcion;
		this.domicilio = domicilio;
		this.myEntrega = myEntrega;
	}

	public void addEntrega(Entrega entrega) {
		myEntrega.add(entrega);
		
	}
	
}
	
