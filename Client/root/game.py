import cfg


#sub self.serverCommander=stringCommander.Analyzer()
#Adauga

		if app.ENABLE_SPECULAR_SYSTEM:
			self.serverCommander.SAFE_RegisterCallBack("SaveSpecularColor", self.SaveSpecularColor)
			
#La sfarsitul fisierului, adauga:

	if app.ENABLE_SPECULAR_SYSTEM:
		def SaveSpecularColor(self, type, name, r, g, b, a):
			if not type:
				return

			cfgType = -1

			if int(type) == 1:
				cfgType = cfg.SAVE_SPECULAR_COLOR_WEAPON
			elif int(type) == 2:
				cfgType = cfg.SAVE_SPECULAR_COLOR_ARMOR
			elif int(type) == 3:
				cfgType = cfg.SAVE_SPECULAR_COLOR_HAIR

			if cfgType == -1:
				return
			
			slot = int(cfg.Get(cfg.SAVE_CHARACTER_SLOT, "slot_{}".format(str(name)), "0"))
			cfg.Set(cfgType, "R_{}_{}".format(slot, str(name)), int(r))
			cfg.Set(cfgType, "G_{}_{}".format(slot, str(name)), int(g))
			cfg.Set(cfgType, "B_{}_{}".format(slot, str(name)), int(b))
			cfg.Set(cfgType, "A_{}_{}".format(slot, str(name)), int(a))