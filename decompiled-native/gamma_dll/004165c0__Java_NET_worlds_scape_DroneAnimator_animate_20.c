// 004165c0 _Java_NET_worlds_scape_DroneAnimator_animate@20 [Global]
// programa: gamma.dll

float10 _Java_NET_worlds_scape_DroneAnimator_animate_20
                  (int *param_1,undefined4 param_2,uint param_3,undefined4 param_4,uint param_5)

{
  byte *pbVar1;
  undefined4 *puVar2;
  float10 fVar3;
  
                    /* 0x165c0  211  _Java_NET_worlds_scape_DroneAnimator_animate@20 */
  pbVar1 = (byte *)(**(code **)(*param_1 + 0x2a4))(param_1,param_4,0);
  puVar2 = (undefined4 *)FUN_00402e90(param_1,param_2,&DAT_0046ffe0);
  fVar3 = FUN_004355a0(puVar2,param_1,param_3,pbVar1,param_5);
  (**(code **)(*param_1 + 0x2a8))(param_1,param_4,pbVar1);
  return (float10)(float)fVar3;
}


