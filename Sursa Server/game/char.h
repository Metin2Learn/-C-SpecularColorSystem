// Cauta si inlocuieste:

void				UpdatePacket();


// Cu 

#ifdef ENABLE_SPECULAR_SYSTEM
		void				UpdatePacket(bool bUnequip = false);
#else
		void				UpdatePacket();
#endif