#Inauntrul class ItemToolTip(ToolTip):
#Cauta def __init__(self, *args, **kwargs):
#In ea, adauga:

self.interface = None


#Dupa functia def __DragonSoulInfoString (self, dwVnum):
#Adauga:

	def BindInterface(self, interface):
		from _weakref import proxy
		self.interface = proxy(interface)

	if app.ENABLE_RENDER_TARGET:
		def ModelPreviewFull(self, itemVnum, slotIndex = -1):
			item.SelectItem(itemVnum)
			itemType = item.GetItemType()
			itemSubType = item.GetItemSubType()

			#IsPets   = (itemVnum >= 53001 and itemVnum <= 53100)
			#IsMounts = (itemVnum >= 52001 and itemVnum <= 52100)

			IsArmor    = (itemType == item.ITEM_TYPE_ARMOR and itemSubType == item.ARMOR_BODY)
			IsWeapon   = (itemType == item.ITEM_TYPE_WEAPON)

			IsCostumeBody  = (itemType == item.ITEM_TYPE_COSTUME and itemSubType == item.COSTUME_TYPE_BODY)
			IsCostumeHair  = (itemType == item.ITEM_TYPE_COSTUME and itemSubType == item.COSTUME_TYPE_HAIR)
			#IsCostumeWeapon= (itemType == item.ITEM_TYPE_COSTUME and itemSubType == item.COSTUME_TYPE_WEAPON)

			if IsWeapon:
				self.interface.wndTargetRender.DisplayUser(self.ItemGetRace(itemVnum), itemVnum, 0, 0, 0, 0, slotIndex)
				self.interface.wndTargetRender.Open()
			elif IsArmor or IsCostumeBody:
				self.interface.wndTargetRender.DisplayUser(self.ItemGetRace(itemVnum), 0, itemVnum, 0, 0, 0, slotIndex)
				self.interface.wndTargetRender.Open()
			elif IsCostumeHair:
				self.interface.wndTargetRender.DisplayUser(self.ItemGetRace(itemVnum), 0, 0, item.GetValue(3), 0, 0, slotIndex)
				self.interface.wndTargetRender.Open()

		def AppendRenderingTooltip(self, itemVnum):
			item.SelectItem(itemVnum)
			itemType = item.GetItemType()
			itemSubType = item.GetItemSubType()
			if  itemType == item.ITEM_TYPE_WEAPON or\
				(itemType == item.ITEM_TYPE_ARMOR and itemSubType == item.ARMOR_BODY) or\
				(itemType == item.ITEM_TYPE_COSTUME and itemSubType == item.COSTUME_TYPE_BODY) or\
				(itemType == item.ITEM_TYPE_COSTUME and itemSubType == item.COSTUME_TYPE_HAIR) or\
				(itemType == item.ITEM_TYPE_COSTUME and itemSubType == item.COSTUME_TYPE_WEAPON):
				self.AppendSpace(5)
				COLOR_TEXT_SHORTCUT = grp.GenerateColor(1.0,1.0,0.5,1.0)
				self.AppendTextLine("|Eemoji/key_shift|e + |Eemoji/key_rclick|e - Item Preview", COLOR_TEXT_SHORTCUT)
				
		def ItemGetRace(self, itemVnum = 0):
			races_m = []
			races_f = []
			MALES = [0, 5, 2, 7]
			FEMALES = [4, 1, 6, 3]
			
			item.SelectItem(itemVnum)
			
			if not item.IsAntiFlag(item.ITEM_ANTIFLAG_WARRIOR):
				races_m.append(MALES[0])
				races_f.append(FEMALES[0])
			if not item.IsAntiFlag(item.ITEM_ANTIFLAG_ASSASSIN):
				races_m.append(MALES[1])
				races_f.append(FEMALES[1])
			if not item.IsAntiFlag(item.ITEM_ANTIFLAG_SURA):
				races_m.append(MALES[2])
				races_f.append(FEMALES[2])
			if not item.IsAntiFlag(item.ITEM_ANTIFLAG_SHAMAN):
				races_m.append(MALES[3])
				races_f.append(FEMALES[3])
			
			if item.IsAntiFlag(item.ITEM_ANTIFLAG_FEMALE):
				races_f = []
			if item.IsAntiFlag(item.ITEM_ANTIFLAG_MALE):
				races_m = []
			
			race = player.GetRace()
			
			if race in races_m or race in races_f:
				return race
			
			if len(races_f) == 0:
				if race in races_m:
					return race
				if len(races_m) > 2:
					return app.GetRandom(0, len(races_m) - 1)
				return races_m[0]
			
			elif len(races_m) == 0:
				if race in races_f:
					return race
				if len(races_f) > 2:
					return app.GetRandom(0, len(races_f) - 1)
				return races_f[0]
			
			else:
				table = []
				for i in races_f:
					table.append(i)
				for i in races_m:
					table.append(i)
					
				return table[app.GetRandom(0, len(table) - 1)]
			
			
			return race

	if app.ENABLE_SPECULAR_SYSTEM:
		def AppendSpecularColorTooltip(self):
			self.AppendSpace(5)
			COLOR_TEXT_SHORTCUT = grp.GenerateColor(1.0,1.0,0.5,1.0)
			self.AppendTextLine("%s + %s - Set Specular Color" % ("|Eemoji/key_shift|e", "|Eemoji/key_lclick|e"), COLOR_TEXT_SHORTCUT)

		if app.ENABLE_EFFECT_COLOR_SYSTEM:
			def AppendEffectColorTooltip(self, itemVnum):
				self.AppendSpace(5)
				COLOR_TEXT_SHORTCUT = grp.GenerateColor(1.0,1.0,0.5,1.0)
				self.AppendTextLine("%s + %s - Set Effect Color" % ("|Eemoji/key_shift|e", "|Eemoji/key_lclick|e"), COLOR_TEXT_SHORTCUT)