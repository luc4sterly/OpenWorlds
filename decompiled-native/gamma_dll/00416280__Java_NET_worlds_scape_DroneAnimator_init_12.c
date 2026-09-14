// 00416280 _Java_NET_worlds_scape_DroneAnimator_init@12 [Global]
// programa: gamma.dll

void _Java_NET_worlds_scape_DroneAnimator_init_12
               (int *param_1,undefined4 param_2,undefined4 param_3)

{
  bool bVar1;
  char *pcVar2;
  undefined4 uVar3;
  
                    /* 0x16280  218  _Java_NET_worlds_scape_DroneAnimator_init@12 */
  pcVar2 = (char *)(**(code **)(*param_1 + 0x2a4))(param_1,param_3,0);
  FUN_004349d0(pcVar2);
  (**(code **)(*param_1 + 0x2a8))(param_1,param_3,pcVar2);
  if (DAT_004894f0 == 0) {
    uVar3 = (**(code **)(*param_1 + 0x18))(param_1,s_java_util_Vector_0046ffe8);
    DAT_004894f0 = (**(code **)(*param_1 + 0x54))(param_1,uVar3);
    if (DAT_004894f0 == 0) {
      FUN_00402800(s_nDroneAnimator_0046fffc,0x2f);
    }
    DAT_004894f4 = (**(code **)(*param_1 + 0x84))
                             (param_1,DAT_004894f0,s_addElement_00470024,
                              s__Ljava_lang_Object__V_0047000c);
    DAT_004894f8 = (**(code **)(*param_1 + 0x84))
                             (param_1,DAT_004894f0,s_<init>_00470034,&DAT_00470030);
    bVar1 = false;
    if ((DAT_004894f4 != 0) && (DAT_004894f8 != 0)) {
      bVar1 = true;
    }
    if (!bVar1) {
      FUN_00402800(s_nDroneAnimator_0046fffc,0x33);
    }
  }
  return;
}


