package ParcialObjetos;

public class RolAdminDTO extends RolUsuarioDTO{
	
	private String clave;

	public RolAdminDTO(UsuarioDTO myUsuario, String clave) {
		super(myUsuario);
		this.clave = clave;
	}

	@Override
	public boolean esComensal() {
		return false;
	}
	
	
	
}
