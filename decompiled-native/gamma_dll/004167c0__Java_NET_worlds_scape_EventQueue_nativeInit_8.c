// 004167c0 _Java_NET_worlds_scape_EventQueue_nativeInit@8 [Global]
// programa: gamma.dll

void _Java_NET_worlds_scape_EventQueue_nativeInit_8(int *param_1)

{
  bool bVar1;
  bool bVar2;
  undefined4 uVar3;
  
                    /* 0x167c0  227  _Java_NET_worlds_scape_EventQueue_nativeInit@8 */
  if (DAT_00489508 == 0) {
    uVar3 = (**(code **)(*param_1 + 0x18))(param_1,s_NET_worlds_scape_EventQueue_00470040);
    DAT_00489508 = (**(code **)(*param_1 + 0x54))(param_1,uVar3);
    if (DAT_00489508 == 0) {
      FUN_00402800(s_nEventQueue_0047005c,0x1e);
    }
    DAT_0048950c = (**(code **)(*param_1 + 0x178))(param_1,DAT_00489508,&DAT_0047006c,&DAT_00470068)
    ;
    DAT_00489510 = (**(code **)(*param_1 + 0x178))(param_1,DAT_00489508,&DAT_00470074,&DAT_00470070)
    ;
    DAT_00489514 = (**(code **)(*param_1 + 0x178))(param_1,DAT_00489508,&DAT_0047007c,&DAT_00470070)
    ;
    DAT_00489518 = (**(code **)(*param_1 + 0x178))(param_1,DAT_00489508,&DAT_00470084,&DAT_00470070)
    ;
    DAT_0048951c = (**(code **)(*param_1 + 0x178))(param_1,DAT_00489508,&DAT_00470088,&DAT_00470070)
    ;
    bVar1 = false;
    bVar2 = false;
    if ((DAT_0048950c != 0) && (DAT_00489510 != 0)) {
      bVar1 = true;
    }
    if ((bVar1) && (DAT_00489514 != 0)) {
      bVar2 = true;
    }
    if (!bVar2) {
      FUN_00402800(s_nEventQueue_0047005c,0x25);
    }
    bVar1 = false;
    if ((DAT_00489518 != 0) && (DAT_0048951c != 0)) {
      bVar1 = true;
    }
    if (!bVar1) {
      FUN_00402800(s_nEventQueue_0047005c,0x26);
    }
  }
  return;
}


