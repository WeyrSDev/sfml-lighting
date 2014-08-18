/***********************************************************************
     * File       : controls.hpp
     * Created    : Aug 18, 2016
     * Copyright  : (C) 2014 Achpile
     * Author     : Fedosov Alexander
     * Email      : achpile@gmail.com

***********************************************************************/
#ifndef __CONTROLS
#define __CONTROLS


struct DemoControls {
	sfg::Desktop desktop;

	sfg::Adjustment::Ptr ambIntensityAdj;
	sfg::Adjustment::Ptr ambColR;
	sfg::Adjustment::Ptr ambColG;
	sfg::Adjustment::Ptr ambColB;

	sfg::Adjustment::Ptr brIntensityAdj;
	sfg::Adjustment::Ptr brColR;
	sfg::Adjustment::Ptr brColG;
	sfg::Adjustment::Ptr brColB;

	sfg::ComboBox::Ptr   brStyle;
	sfg::SpinButton::Ptr brTime;

	void init(DemoState *state);
	void update();
	void render();
};


#endif
