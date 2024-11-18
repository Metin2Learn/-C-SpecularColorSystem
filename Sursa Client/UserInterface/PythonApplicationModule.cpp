#ifdef ENABLE_RENDER_TARGET
	PyModule_AddIntConstant(poModule, "ENABLE_RENDER_TARGET", 1);
#else
	PyModule_AddIntConstant(poModule, "ENABLE_RENDER_TARGET", 0);
#endif
#ifdef ENABLE_SPECULAR_SYSTEM
	PyModule_AddIntConstant(poModule, "ENABLE_SPECULAR_SYSTEM", 1);
#else
	PyModule_AddIntConstant(poModule, "ENABLE_SPECULAR_SYSTEM", 0);
#endif
#ifdef ENABLE_EFFECT_COLOR_SYSTEM
	PyModule_AddIntConstant(poModule, "ENABLE_EFFECT_COLOR_SYSTEM", 1);
#else
	PyModule_AddIntConstant(poModule, "ENABLE_EFFECT_COLOR_SYSTEM", 0);
#endif