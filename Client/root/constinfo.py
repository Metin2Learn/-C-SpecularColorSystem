import chrmgr, player, chat, net, chr


#Adauga la sfarsitul fisierului:

if app.ENABLE_SPECULAR_SYSTEM:

	def GetFilterPart(itemVnum):
		item.SelectItem(itemVnum)
		itemType = item.GetItemType()
		itemSubType = item.GetItemSubType()
		
		if itemType == item.ITEM_TYPE_ARMOR and itemSubType == item.ARMOR_BODY or itemType == item.ITEM_TYPE_COSTUME and itemSubType == item.COSTUME_TYPE_BODY:
			return 0
		elif itemType == item.ITEM_TYPE_WEAPON and (itemSubType == item.WEAPON_DAGGER or itemSubType == item.WEAPON_BOW):
			return 3
		elif itemType == item.ITEM_TYPE_WEAPON:
			return 1
		elif itemType == item.ITEM_TYPE_COSTUME and itemSubType == item.COSTUME_TYPE_HAIR:
			return 4
				
		return -1
		
	def IsSpecularItem(itemVnum):
		item.SelectItem(itemVnum)
		itemType = item.GetItemType()
		itemSubType = item.GetItemSubType()

		IsArmor = (itemType == item.ITEM_TYPE_ARMOR and itemSubType == item.ARMOR_BODY)
		IsWeapon = (itemType == item.ITEM_TYPE_WEAPON and (itemSubType <= item.WEAPON_FAN))

		IsCostumeBody = (itemType == item.ITEM_TYPE_COSTUME and itemSubType == item.COSTUME_TYPE_BODY)
		IsCostumeHair = (itemType == item.ITEM_TYPE_COSTUME and itemSubType == item.COSTUME_TYPE_HAIR)

		# if item.IsFlag(item.ITEM_FLAG_COLOR):
			# return True

		if IsArmor:
			return True

		if IsWeapon:
			return True

		if IsCostumeBody:
			return True

		if IsCostumeHair:
			return True

		return False

	def IsAllowedItemSpecularColor(itemVnum):
		item.SelectItem(itemVnum)
		itemType = item.GetItemType()
		itemSubType = item.GetItemSubType()

		if not IsSpecularItem(itemVnum):
			return False

		IsArmor = (itemType == item.ITEM_TYPE_ARMOR and itemSubType == item.ARMOR_BODY)
		IsWeapon = (itemType == item.ITEM_TYPE_WEAPON)

		IsCostumeBody = (itemType == item.ITEM_TYPE_COSTUME and itemSubType == item.COSTUME_TYPE_BODY)
		IsCostumeHair = (itemType == item.ITEM_TYPE_COSTUME and itemSubType == item.COSTUME_TYPE_HAIR)

		races_m = []
		races_f = []
		MALES = [0, 5, 2, 7]
		FEMALES = [4, 1, 6, 3]

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

		if not player.GetRace() in races_m and not player.GetRace() in races_f:
			return False
				
		if IsWeapon or IsArmor or IsCostumeBody or IsCostumeHair:
			return True
			
		return False

	if app.ENABLE_EFFECT_COLOR_SYSTEM:
		def IsAllowedItemEffectColor(itemVnum):
			item.SelectItem(itemVnum)
			itemType = item.GetItemType()
			itemSubType = item.GetItemSubType()

			if not item.IsFlag(item.ITEM_FLAG_COLOR):
				return False

			# IsShining = (itemType == item.ITEM_TYPE_SHINING)

			# if IsShining:
				# return True
				
			return False
