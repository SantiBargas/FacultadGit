package ParcialObjetos;

public class RolVentanillaDTO extends RolUsuarioDTO{

	private String clave;
	private ComedorDTO myComedor;
	
	
	public RolVentanillaDTO(UsuarioDTO myUsuario, String clave, ComedorDTO myComedor) {
		super(myUsuario);
		this.clave = clave;
		this.myComedor = myComedor;
	}

	@Override
	public boolean esComensal() {
		// TODO Auto-generated method stub
		return false;
	}
}
