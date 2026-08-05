Route1_Frlg_MapScripts::
	.byte 0

Route1_EventScript_MartClerk::
	lock
	faceplayer
	goto_if_set FLAG_GOT_POTION_ON_ROUTE_1, Route1_EventScript_AlreadyGotPotion
	msgbox Route1_Text_WorkAtPokeMartTakeSample
	textcolor NPC_TEXT_COLOR_NEUTRAL
	checkitemspace ITEM_POTION
	goto_if_eq VAR_RESULT, FALSE, EventScript_BagIsFull
	bufferitemname STR_VAR_2, ITEM_POTION
	playfanfare MUS_LEVEL_UP
	message gText_ObtainedTheItem
	waitmessage
	waitfanfare
	additem ITEM_POTION
	msgbox Route1_Text_PutPotionAway
	call EventScript_RestorePrevTextColor
	setflag FLAG_GOT_POTION_ON_ROUTE_1
	release
	end

Route1_EventScript_AlreadyGotPotion::
	msgbox Route1_Text_ComeSeeUsIfYouNeedPokeBalls
	release
	end

Route1_EventScript_Boy::
	msgbox Route1_Text_CanJumpFromLedges, MSGBOX_NPC
	end

Route1_EventScript_RouteSign::
	msgbox Route1_Text_RouteSign, MSGBOX_SIGN
	end

Route1_EventScript_Chung::
	trainerbattle_single TRAINER_BIRD_KEEPER_CHUNG, Route1_Text_ChungIntro, Route1_Text_ChungDefeat
	msgbox Route1_Text_ChungPostBattle, MSGBOX_AUTOCLOSE
	end

Route1_EventScript_FishingNovice::
	lock
	faceplayer
	goto_if_set FLAG_GOT_OLD_ROD, Route1_EventScript_AlreadyGotOldRod
	msgbox Route1_Text_NoTimeToExplain
	checkitemspace ITEM_OLD_ROD
	goto_if_eq VAR_RESULT, FALSE, Route1_EventScript_NoRoomForOldRod
	additem ITEM_OLD_ROD
	msgreceiveditem Route1_Text_ReceivedOldRodFromFishingNovice, ITEM_OLD_ROD
	setflag FLAG_GOT_OLD_ROD
	msgbox Route1_Text_FishSmallPondOcean
	release
	end

Route1_EventScript_AlreadyGotOldRod::
	msgbox Route1_Text_DidYouFindGoldeen
	release
	end

Route1_EventScript_NoRoomForOldRod::
	msgbox Route1_Text_NoRoomForNiceGift
	release
	end

Route1_Text_NoTimeToExplain::
	.string "No time to explain! Take this.$"

Route1_Text_ReceivedOldRodFromFishingNovice::
	.string "{PLAYER} received an OLD ROD from\n"
	.string "the FISHING NOVICE.$"

Route1_Text_FishSmallPondOcean::
	.string "You'll come across small ponds like\n"
	.string "this one during your journey.\p"
	.string "They're good fishing practice.$"

Route1_Text_NoRoomForNiceGift::
	.string "What do you mean you have no room\n"
	.string "for it?!$"

Route1_Text_DidYouFindGoldeen::
	.string "Did you find a GOLDEEN yet?$"

Route1_Text_WorkAtPokeMartTakeSample::
	.string "Hi!\n"
	.string "I work at a POKéMON MART.\p"
	.string "It's part of a convenient chain\n"
	.string "selling all sorts of items.\p"
	.string "Please, visit us in VIRIDIAN CITY.\p"
	.string "I know, I'll give you a sample.\n"
	.string "Here you go!$"

Route1_Text_ComeSeeUsIfYouNeedPokeBalls::
	.string "Please come see us if you need\n"
	.string "POKé BALLS for catching POKéMON.$"

Route1_Text_PutPotionAway::
	.string "{PLAYER} put the POTION away in\n"
	.string "the BAG's ITEMS POCKET.$"

Route1_Text_CanJumpFromLedges::
	.string "See those ledges along the road?\p"
	.string "It's a bit scary, but you can jump\n"
	.string "from them.\p"
	.string "You can get back to PALLET TOWN\n"
	.string "quicker that way.$"

Route1_Text_RouteSign::
	.string "ROUTE 1\n"
	.string "PALLET TOWN - VIRIDIAN CITY$"

Route1_Text_ChungIntro::
	.string "Don't scare away the birds!$"

Route1_Text_ChungDefeat::
	.string "Ugh!\n"
	.string "They flew away.$"

Route1_Text_ChungPostBattle::
	.string "I'm looking for a MURKROW.$"
	
