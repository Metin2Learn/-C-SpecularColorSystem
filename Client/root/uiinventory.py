import cfg



#In functia def RefreshCostumeSlot(self):
#Inlocuieste:

			if app.ENABLE_SPECULAR_SYSTEM:
				r, g, b, a = player.GetSpecularColor(slotNumber)
				if r == 0 and g == 0 and b == 0:
					r, g, b = 255, 255, 255
				self.wndEquip.SetItemSlot(slotNumber, getItemVNum(slotNumber), 0, (1.0, 1.0, 1.0, 1.0), 0, "icon/item/noicon.tga", (float(r) / 255.0, float(g) / 255.0, float(b) / 255.0, 1.0))
			else:
				self.wndEquip.SetItemSlot(slotNumber, getItemVNum(slotNumber), 0)
				
				
#In functia def RefreshBagSlotWindow(self):
#Inlocuieste:

			if app.ENABLE_SPECULAR_SYSTEM:
				r, g, b, a = player.GetSpecularColor(slotNumber)
				if r == 0 and g == 0 and b == 0:
					r, g, b = 255, 255, 255
				setItemVNum(i, itemVnum, itemCount, (1.0, 1.0, 1.0, 1.0), 0, "icon/item/noicon.tga", (float(r) / 255.0, float(g) / 255.0, float(b) / 255.0, 1.0))
			else:
				setItemVNum(i, itemVnum, itemCount)
				
#In functia def RefreshEquipSlotWindow(self):
#Sub setItemVNum(slotNumber, getItemVNum(slotNumber), itemCount)
#Adauga:

			if app.ENABLE_SPECULAR_SYSTEM:
				r, g, b, a = player.GetSpecularColor(slotNumber)
				if r == 0 and g == 0 and b == 0:
					r, g, b = 255, 255, 255
				self.wndEquip.SetItemSlot(slotNumber, getItemVNum(slotNumber), itemCount, (1.0, 1.0, 1.0, 1.0), 0, "icon/item/noicon.tga", (float(r) / 255.0, float(g) / 255.0, float(b) / 255.0, 1.0))
				self.wndEquip.SetItemSlot(211, getItemVNum(211), itemCount, (1.0, 1.0, 1.0, 1.0), 0, "icon/item/noicon.tga", (float(r) / 255.0, float(g) / 255.0, float(b) / 255.0, 1.0))
			else:
				self.wndEquip.SetItemSlot(slotNumber, getItemVNum(slotNumber), itemCount)
				self.wndEquip.SetItemSlot(211, getItemVNum(211), itemCount)
				
				
#Sub elif app.IsPressed(app.DIK_LSHIFT):
#Adauga:

				if app.ENABLE_SPECULAR_SYSTEM:
					itemIndex = player.GetItemIndex(itemSlotIndex)
					
					if constInfo.IsAllowedItemSpecularColor(itemIndex):
						if player.IsEquipmentSlot(itemSlotIndex):
							self.interface.OpenSpecularColorBoard(itemIndex, itemSlotIndex, True)
						else:
							self.interface.OpenSpecularColorBoard(itemIndex, itemSlotIndex, False)
					elif app.ENABLE_EFFECT_COLOR_SYSTEM and constInfo.IsAllowedItemEffectColor(itemIndex):
						self.interface.OpenEffectColorBoard(itemIndex, itemSlotIndex, True)
						

#Inauntrul def ShowToolTip(self, slotIndex):
#Chiar sub el, adauga:

itemVnum = player.GetItemIndex(slotIndex)

#Sub self.tooltipItem.SetInventoryItem(slotIndex)

			if app.ENABLE_RENDER_TARGET:
				self.tooltipItem.AppendRenderingTooltip(itemVnum)

			if app.ENABLE_SPECULAR_SYSTEM:
				if constInfo.IsAllowedItemSpecularColor(itemVnum):
					self.tooltipItem.AppendSpecularColorTooltip()
					
#Trebuie sa ai ceva de genul asta:

	def ShowToolTip(self, slotIndex):
		itemVnum = player.GetItemIndex(slotIndex)
		if None != self.tooltipItem:
			self.tooltipItem.SetInventoryItem(slotIndex)

			if app.ENABLE_RENDER_TARGET:
				self.tooltipItem.AppendRenderingTooltip(itemVnum)

			if app.ENABLE_SPECULAR_SYSTEM:
				if constInfo.IsAllowedItemSpecularColor(itemVnum):
					self.tooltipItem.AppendSpecularColorTooltip()
					
#Sub functia if item.IsFlag(item.ITEM_FLAG_CONFIRM_WHEN_USE):
#Adauga:

		elif app.ENABLE_RENDER_TARGET and app.IsPressed(app.DIK_LSHIFT):
			self.tooltipItem.ModelPreviewFull(ItemVNum, slotIndex)