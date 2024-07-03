package ParcialObjetos;

import java.util.Calendar;

public class Entrega {

	private Calendar fecha;
	private Cupon myCupon;
	private RolVentanillaDTO myRolVentanilla;
	private ComedorDTO myComedor;
	
	public Entrega(Calendar fecha, Cupon myCupon, RolVentanillaDTO myRolVentanilla, ComedorDTO myComedor) {
		super();
		this.fecha = fecha;
		this.myCupon = myCupon;
		this.myRolVentanilla = myRolVentanilla;
		this.myComedor = myComedor;
		myComedor.addEntrega(this);
		myCupon.addEntrega(this);
	}

	
	
}
