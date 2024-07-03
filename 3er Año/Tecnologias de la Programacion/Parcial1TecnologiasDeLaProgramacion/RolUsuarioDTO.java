package ParcialObjetos;

public abstract class RolUsuarioDTO {

	private UsuarioDTO myUsuario;

	public RolUsuarioDTO(UsuarioDTO myUsuario) {
		super();
		this.myUsuario = myUsuario;
		myUsuario.addRol(this);
	}

	public abstract boolean esComensal();

	public void mostrarFacultad() {
		if(this.esComensal()==true) {
			RolComensalDTO ARolComensal = (RolComensalDTO)this;
			ARolComensal.mostrarFacultadComensal();
		}
		
	}

	public void mostrarSaldo() {
		if(this.esComensal()==true) {
			RolComensalDTO ARolComensal = (RolComensalDTO)this;
			ARolComensal.mostrarSaldo();
		}
		
	}
	
}
