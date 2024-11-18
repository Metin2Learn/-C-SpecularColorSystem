#In functia def Refresh(self):
#Inlocuieste:

			if app.ENABLE_SPECULAR_SYSTEM:
				r, g, b, a = shop.GetSpecularColor(i)
				if r == 0 and g == 0 and b == 0:
					r, g, b = 255, 255, 255
				setitemVNum(i, getitemVNum(*pos), itemCount, (1.0, 1.0, 1.0, 1.0), 0, "icon/item/noicon.tga", (float(r) / 255.0, float(g) / 255.0, float(b) / 255.0, 1.0))
			else:
				setitemVNum(i, getitemVNum(*pos), itemCount)