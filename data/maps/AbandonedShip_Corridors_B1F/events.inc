AbandonedShip_Corridors_B1F_EventObjects:: @ 838E238
	object_event 1, EVENT_OBJ_GFX_TUBER_M, 0, 2, 8, 3, 2, 1, 1, 0, 0, AbandonedShip_Corridors_B1F_EventScript_15E9CA, 0
	object_event 2, EVENT_OBJ_GFX_SAILOR, 0, 9, 6, 3, 14, 0, 0, 1, 4, AbandonedShip_Corridors_B1F_EventScript_15EA1E, 0

AbandonedShip_Corridors_B1F_MapWarps:: @ 838E268
	warp_def 6, 4, 3, 2, MAP_ABANDONED_SHIP_ROOMS2_B1F
	warp_def 3, 4, 3, 0, MAP_ABANDONED_SHIP_ROOMS2_B1F
	warp_def 5, 7, 3, 0, MAP_ABANDONED_SHIP_ROOMS_B1F
	warp_def 8, 7, 3, 1, MAP_ABANDONED_SHIP_ROOMS_B1F
	warp_def 11, 7, 3, 2, MAP_ABANDONED_SHIP_ROOMS_B1F
	warp_def 11, 4, 3, 0, MAP_ABANDONED_SHIP_ROOM_B1F
	warp_def 0, 2, 3, 10, MAP_ABANDONED_SHIP_CORRIDORS_1F
	warp_def 8, 2, 3, 9, MAP_ABANDONED_SHIP_CORRIDORS_1F

AbandonedShip_Corridors_B1F_MapBGEvents:: @ 838E2A8
	bg_event 11, 4, 3, 0, 0, AbandonedShip_Corridors_B1F_EventScript_15E9D3

AbandonedShip_Corridors_B1F_MapEvents:: @ 838E2B4
	map_events AbandonedShip_Corridors_B1F_EventObjects, AbandonedShip_Corridors_B1F_MapWarps, 0x0, AbandonedShip_Corridors_B1F_MapBGEvents
