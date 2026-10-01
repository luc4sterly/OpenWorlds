// 0041ae50 _Java_NET_worlds_scape_Portal_nativeInit@8 [Global]
// program: gamma.dll

void _Java_NET_worlds_scape_Portal_nativeInit_8(int *param_1)

{
  bool bVar1;
  bool bVar2;
  undefined4 uVar3;
  
                    /* 0x1ae50  262  _Java_NET_worlds_scape_Portal_nativeInit@8 */
  if (DAT_0049fce0 == 0) {
    uVar3 = (**(code **)(*param_1 + 0x18))(param_1,s_NET_worlds_scape_Portal_00470768);
    DAT_0049fce0 = (**(code **)(*param_1 + 0x54))(param_1,uVar3);
    if (DAT_0049fce0 == 0) {
      FUN_00402800(s_nPortal_00470780,0x62);
    }
    DAT_004895f0 = (**(code **)(*param_1 + 0x178))
                             (param_1,DAT_0049fce0,s__fartheta_0047078c,&DAT_00470788);
    DAT_004895f4 = (**(code **)(*param_1 + 0x178))
                             (param_1,DAT_0049fce0,s__farx_00470798,&DAT_00470788);
    DAT_004895f8 = (**(code **)(*param_1 + 0x178))
                             (param_1,DAT_0049fce0,s__fary_004707a0,&DAT_00470788);
    DAT_004895fc = (**(code **)(*param_1 + 0x178))
                             (param_1,DAT_0049fce0,s__farz_004707a8,&DAT_00470788);
    DAT_00489600 = (**(code **)(*param_1 + 0x178))
                             (param_1,DAT_0049fce0,s__state_004707b4,&DAT_004707b0);
    DAT_00489604 = (**(code **)(*param_1 + 0x178))
                             (param_1,DAT_0049fce0,s__p2pxform_004707dc,
                              s_LNET_worlds_scape_Transform__004707bc);
    DAT_00489608 = (**(code **)(*param_1 + 0x178))
                             (param_1,DAT_0049fce0,s__farSidePortal_00470804,
                              s_LNET_worlds_scape_Portal__004707e8);
    DAT_0048960c = (**(code **)(*param_1 + 0x178))
                             (param_1,DAT_0049fce0,s__changeNum_00470814,&DAT_004707b0);
    DAT_00489610 = (**(code **)(*param_1 + 0x178))
                             (param_1,DAT_0049fce0,s__farChangeNum_00470820,&DAT_004707b0);
    DAT_00489614 = (**(code **)(*param_1 + 0x178))
                             (param_1,DAT_0049fce0,s__farSideRoom_00470848,
                              s_LNET_worlds_scape_Room__00470830);
    bVar1 = false;
    bVar2 = false;
    if ((DAT_004895f0 != 0) && (DAT_004895f4 != 0)) {
      bVar1 = true;
    }
    if ((bVar1) && (DAT_004895f8 != 0)) {
      bVar2 = true;
    }
    if (!bVar2) {
      FUN_00402800(s_nPortal_00470780,0x71);
    }
    bVar1 = false;
    bVar2 = false;
    if ((DAT_004895fc != 0) && (DAT_00489600 != 0)) {
      bVar1 = true;
    }
    if ((bVar1) && (DAT_00489604 != 0)) {
      bVar2 = true;
    }
    if (!bVar2) {
      FUN_00402800(s_nPortal_00470780,0x72);
    }
    bVar1 = false;
    if ((DAT_00489608 != 0) && (DAT_0048960c != 0)) {
      bVar1 = true;
    }
    if (!bVar1) {
      FUN_00402800(s_nPortal_00470780,0x73);
    }
    bVar1 = false;
    if ((DAT_00489610 != 0) && (DAT_00489614 != 0)) {
      bVar1 = true;
    }
    if (!bVar1) {
      FUN_00402800(s_nPortal_00470780,0x74);
    }
    DAT_00489618 = (**(code **)(*param_1 + 0x84))
                             (param_1,DAT_0049fce0,s_reset_00470860,&DAT_00470858);
    DAT_0048961c = (**(code **)(*param_1 + 0x84))
                             (param_1,DAT_0049fce0,s_recomputeFarPosition_0047086c,&DAT_00470868);
    DAT_00489620 = (**(code **)(*param_1 + 0x84))
                             (param_1,DAT_0049fce0,s_getRoom_004708a0,
                              s___LNET_worlds_scape_Room__00470884);
  }
  return;
}


