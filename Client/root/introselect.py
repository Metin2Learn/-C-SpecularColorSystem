import cfg

#Inauntrul def MakeCharacter(self, index, id, name, race, form, hair):
#Cauta si inlocuieste SetArmor si SetHair

		if app.ENABLE_SPECULAR_SYSTEM:
			armorColorR = int(cfg.Get(cfg.SAVE_SPECULAR_COLOR_ARMOR, "R_{}_{}".format(index, name), "0"))
			armorColorG = int(cfg.Get(cfg.SAVE_SPECULAR_COLOR_ARMOR, "G_{}_{}".format(index, name), "0"))
			armorColorB = int(cfg.Get(cfg.SAVE_SPECULAR_COLOR_ARMOR, "B_{}_{}".format(index, name), "0"))
			armorColorA = int(cfg.Get(cfg.SAVE_SPECULAR_COLOR_ARMOR, "A_{}_{}".format(index, name), "0"))
			hairColorR = int(cfg.Get(cfg.SAVE_SPECULAR_COLOR_HAIR, "R_{}_{}".format(index, name), "0"))
			hairColorG = int(cfg.Get(cfg.SAVE_SPECULAR_COLOR_HAIR, "G_{}_{}".format(index, name), "0"))
			hairColorB = int(cfg.Get(cfg.SAVE_SPECULAR_COLOR_HAIR, "B_{}_{}".format(index, name), "0"))
			hairColorA = int(cfg.Get(cfg.SAVE_SPECULAR_COLOR_HAIR, "A_{}_{}".format(index, name), "0"))

			if armorColorR > 0 or armorColorG > 0 or armorColorB > 0 or armorColorA > 0:
				chr.SetArmor(form, True)
			else:
				chr.SetArmor(form)

			if hairColorR > 0 or hairColorG > 0 or hairColorB > 0 or hairColorA > 0:
				chr.SetHair(hair, True)
			else:
				chr.SetHair(hair)
		else:
			chr.SetArmor(form)
			chr.SetHair(hair)
			
			
#Sub chr.SetRotation(0.0)
#Adauga

		if app.ENABLE_SPECULAR_SYSTEM:
			part_max = 5

			for i in xrange(part_max):
				if i != 2:
					if i == 1:
						cfgType = cfg.SAVE_SPECULAR_COLOR_WEAPON
					elif i == 0:
						cfgType = cfg.SAVE_SPECULAR_COLOR_ARMOR
					elif i == 4:
						cfgType = cfg.SAVE_SPECULAR_COLOR_HAIR

					if not cfgType:
						return
				
					colorR = int(cfg.Get(cfgType, "R_{}_{}".format(index, name), "0"))
					colorG = int(cfg.Get(cfgType, "G_{}_{}".format(index, name), "0"))
					colorB = int(cfg.Get(cfgType, "B_{}_{}".format(index, name), "0"))
					colorA = int(cfg.Get(cfgType, "A_{}_{}".format(index, name), "0"))
					
					if colorR > 0 or colorG > 0 or colorB > 0 or colorA > 0:
						chr.UpdateSpecularColor(i, colorR, colorG, colorB, colorA)
						
						
#Sub self.startReservingTime = app.GetTime()
#Adauga

		if app.ENABLE_SPECULAR_SYSTEM:
			name = net.GetAccountCharacterSlotDataString(self.slot, net.ACCOUNT_CHARACTER_SLOT_NAME)
			cfg.Set(cfg.SAVE_CHARACTER_SLOT, "slot_{}".format(name), self.slot)