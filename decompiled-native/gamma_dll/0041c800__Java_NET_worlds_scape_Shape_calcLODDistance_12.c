// 0041c800 _Java_NET_worlds_scape_Shape_calcLODDistance@12 [Global]
// programa: gamma.dll

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 _Java_NET_worlds_scape_Shape_calcLODDistance_12
                  (undefined4 param_1,undefined4 param_2,float param_3)

{
  float fVar1;
  int iVar2;
  float10 fVar3;
  float local_120;
  float local_11c;
  CHAR local_108 [256];
  
                    /* 0x1c800  290  _Java_NET_worlds_scape_Shape_calcLODDistance@12 */
  iVar2 = FUN_004010c0(s_minLodDistance_00470a54,200);
  if ((DAT_0049ff64 == 0) || (DAT_0049fcbc == 0)) {
    return (float10)iVar2;
  }
  fVar1 = param_3 * _DAT_00470a64;
  if (DAT_0049ff64 < DAT_0049fcbc) {
    local_120 = (float)_DAT_00470a68 / (float)DAT_0049fcbc;
    local_11c = ((float)DAT_0049ff64 / (float)DAT_0049fcbc) / (float)DAT_0049ff64;
  }
  else {
    local_120 = ((float)DAT_0049fcbc / (float)DAT_0049ff64) / (float)DAT_0049fcbc;
    local_11c = (float)_DAT_00470a68 / (float)DAT_0049ff64;
  }
  FUN_00401120(s_lodBias_00470a74,&DAT_00470a70,local_108,0x100);
  fVar3 = (float10)FUN_00457470((int)local_108);
  fVar1 = (fVar1 / (local_120 * local_11c)) * (float)fVar3;
  if (fVar1 < (float)iVar2) {
    return (float10)iVar2;
  }
  return (float10)fVar1;
}


