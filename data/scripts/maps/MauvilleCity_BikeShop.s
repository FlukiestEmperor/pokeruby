MauvilleCity_BikeShop_MapScripts:: @ 8156795
	.byte 0

MauvilleCity_BikeShop_EventScript_156796:: @ 8156796
	lock
	faceplayer
	checkflag 90
	jumpeq MauvilleCity_BikeShop_EventScript_15686E
	checkflag 89
	jumpeq MauvilleCity_BikeShop_EventScript_1567D1
	msgbox MauvilleCity_BikeShop_Text_180F9F, 4
	msgbox MauvilleCity_BikeShop_Text_181016, 5
	compare RESULT, 1
	jumpeq MauvilleCity_BikeShop_EventScript_156824
	compare RESULT, 0
	jumpeq MauvilleCity_BikeShop_EventScript_156817
	end

MauvilleCity_BikeShop_EventScript_1567D1:: @ 81567D1
	msgbox MauvilleCity_BikeShop_Text_181016, 5
	compare RESULT, 1
	jumpeq MauvilleCity_BikeShop_EventScript_156824
	compare RESULT, 0
	jumpeq MauvilleCity_BikeShop_EventScript_156817
	end

MauvilleCity_BikeShop_EventScript_1567F0:: @ 81567F0
	message MauvilleCity_BikeShop_Text_1810B1
	waittext
	multichoice 21, 8, 12, 1
	switch RESULT
	case 0, MauvilleCity_BikeShop_EventScript_15682D
	case 1, MauvilleCity_BikeShop_EventScript_156847
	end

MauvilleCity_BikeShop_EventScript_156817:: @ 8156817
	setflag 89
	msgbox MauvilleCity_BikeShop_Text_181067, 4
	release
	end

MauvilleCity_BikeShop_EventScript_156824:: @ 8156824
	setflag 90
	jump MauvilleCity_BikeShop_EventScript_1567F0
	end

MauvilleCity_BikeShop_EventScript_15682D:: @ 815682D
	msgbox MauvilleCity_BikeShop_Text_181332, 4
	giveitem ITEM_MACH_BIKE
	jump MauvilleCity_BikeShop_EventScript_156861
	end

MauvilleCity_BikeShop_EventScript_156847:: @ 8156847
	msgbox MauvilleCity_BikeShop_Text_18134A, 4
	giveitem ITEM_ACRO_BIKE
	jump MauvilleCity_BikeShop_EventScript_156861
	end

MauvilleCity_BikeShop_EventScript_156861:: @ 8156861
	msgbox MauvilleCity_BikeShop_Text_181362, 4
	special 130
	release
	end

MauvilleCity_BikeShop_EventScript_15686E:: @ 815686E
	msgbox MauvilleCity_BikeShop_Text_1813A0, 5
	compare RESULT, 1
	jumpeq MauvilleCity_BikeShop_EventScript_15688D
	compare RESULT, 0
	jumpeq MauvilleCity_BikeShop_EventScript_1568BF
	end

MauvilleCity_BikeShop_EventScript_15688D:: @ 815688D
	msgbox MauvilleCity_BikeShop_Text_1813D4, 4
	checkitem ITEM_ACRO_BIKE, 1
	compare RESULT, 1
	jumpeq MauvilleCity_BikeShop_EventScript_1568C9
	checkitem ITEM_MACH_BIKE, 1
	compare RESULT, 1
	jumpeq MauvilleCity_BikeShop_EventScript_1568EA
	msgbox MauvilleCity_BikeShop_Text_181498, 4
	release
	end

MauvilleCity_BikeShop_EventScript_1568BF:: @ 81568BF
	msgbox MauvilleCity_BikeShop_Text_181469, 4
	release
	end

MauvilleCity_BikeShop_EventScript_1568C9:: @ 81568C9
	inccounter 4
	msgbox MauvilleCity_BikeShop_Text_181439, 4
	removeitem ITEM_ACRO_BIKE, 1
	giveitem ITEM_MACH_BIKE
	jump MauvilleCity_BikeShop_EventScript_156861
	end

MauvilleCity_BikeShop_EventScript_1568EA:: @ 81568EA
	inccounter 4
	msgbox MauvilleCity_BikeShop_Text_181408, 4
	removeitem ITEM_MACH_BIKE, 1
	giveitem ITEM_ACRO_BIKE
	jump MauvilleCity_BikeShop_EventScript_156861
	end

MauvilleCity_BikeShop_EventScript_15690B:: @ 815690B
	msgbox MauvilleCity_BikeShop_Text_181568, 2
	end

MauvilleCity_BikeShop_EventScript_156914:: @ 8156914
	message MauvilleCity_BikeShop_Text_1815EA
	waittext
	jump MauvilleCity_BikeShop_EventScript_156920
	end

MauvilleCity_BikeShop_EventScript_156920:: @ 8156920
	multichoice 0, 0, 43, 0
	switch RESULT
	case 0, MauvilleCity_BikeShop_EventScript_156962
	case 1, MauvilleCity_BikeShop_EventScript_15696E
	case 2, MauvilleCity_BikeShop_EventScript_15697A
	case 3, MauvilleCity_BikeShop_EventScript_156986
	case 127, MauvilleCity_BikeShop_EventScript_156986
	end

MauvilleCity_BikeShop_EventScript_156962:: @ 8156962
	message MauvilleCity_BikeShop_Text_18162C
	waittext
	jump MauvilleCity_BikeShop_EventScript_156920
	end

MauvilleCity_BikeShop_EventScript_15696E:: @ 815696E
	message MauvilleCity_BikeShop_Text_1816F5
	waittext
	jump MauvilleCity_BikeShop_EventScript_156920
	end

MauvilleCity_BikeShop_EventScript_15697A:: @ 815697A
	message MauvilleCity_BikeShop_Text_1817BF
	waittext
	jump MauvilleCity_BikeShop_EventScript_156920
	end

MauvilleCity_BikeShop_EventScript_156986:: @ 8156986
	release
	end

MauvilleCity_BikeShop_EventScript_156988:: @ 8156988
	message MauvilleCity_BikeShop_Text_181892
	waittext
	jump MauvilleCity_BikeShop_EventScript_156994
	end

MauvilleCity_BikeShop_EventScript_156994:: @ 8156994
	multichoice 0, 0, 44, 0
	switch RESULT
	case 0, MauvilleCity_BikeShop_EventScript_1569D6
	case 1, MauvilleCity_BikeShop_EventScript_1569E2
	case 2, MauvilleCity_BikeShop_EventScript_1569EE
	case 3, MauvilleCity_BikeShop_EventScript_1569FA
	case 127, MauvilleCity_BikeShop_EventScript_1569FA
	end

MauvilleCity_BikeShop_EventScript_1569D6:: @ 81569D6
	message MauvilleCity_BikeShop_Text_1818D4
	waittext
	jump MauvilleCity_BikeShop_EventScript_156994
	end

MauvilleCity_BikeShop_EventScript_1569E2:: @ 81569E2
	message MauvilleCity_BikeShop_Text_18199A
	waittext
	jump MauvilleCity_BikeShop_EventScript_156994
	end

MauvilleCity_BikeShop_EventScript_1569EE:: @ 81569EE
	message MauvilleCity_BikeShop_Text_181A3D
	waittext
	jump MauvilleCity_BikeShop_EventScript_156994
	end

MauvilleCity_BikeShop_EventScript_1569FA:: @ 81569FA
	release
	end