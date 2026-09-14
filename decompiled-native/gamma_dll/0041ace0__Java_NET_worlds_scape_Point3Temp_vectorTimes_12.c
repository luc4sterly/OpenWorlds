// 0041ace0 _Java_NET_worlds_scape_Point3Temp_vectorTimes@12 [Global]
// programa: gamma.dll

undefined4
_Java_NET_worlds_scape_Point3Temp_vectorTimes_12(int *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  float10 fVar2;
  float local_1c;
  float local_18;
  float local_14;
  
                    /* 0x1ace0  260  _Java_NET_worlds_scape_Point3Temp_vectorTimes@12 */
  fVar2 = (float10)(**(code **)(*param_1 + 0x198))(param_1,param_2,DAT_004895d4);
  local_1c = (float)fVar2;
  fVar2 = (float10)(**(code **)(*param_1 + 0x198))(param_1,param_2,DAT_004895d8);
  local_18 = (float)fVar2;
  fVar2 = (float10)(**(code **)(*param_1 + 0x198))(param_1,param_2,DAT_004895dc);
  local_14 = (float)fVar2;
  uVar1 = FUN_00425380(param_1,param_3);
  FUN_0041a0b0(&local_1c,uVar1);
  (**(code **)(*param_1 + 0x1bc))(param_1,param_2,DAT_004895d4,local_1c);
  (**(code **)(*param_1 + 0x1bc))(param_1,param_2,DAT_004895d8,local_18);
  (**(code **)(*param_1 + 0x1bc))(param_1,param_2,DAT_004895dc,local_14);
  return param_2;
}


