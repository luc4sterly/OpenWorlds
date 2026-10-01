// 1002cea0 FUN_1002cea0 [Global]
// program: RWL21.DLL

int FUN_1002cea0(int param_1,uint *param_2)

{
  float fVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  float local_5c;
  float local_58;
  int local_54 [2];
  int local_4c;
  int local_48;
  float local_44 [17];
  
  if (param_2[0x11] == 1) {
    uVar2 = FUN_10005d00((float *)param_2[0x12],local_44,DAT_1005addc,local_54,&local_5c);
    if (((uVar2 == 0xffffffff) || (local_4c < 1)) || (iVar4 = 1, local_48 < 1)) {
      iVar4 = 0;
    }
    if (((undefined4 *)param_2[0x12])[99] != 1) {
      FUN_10030b70((undefined4 *)param_2[0x12]);
    }
    if (iVar4 != 0) {
      *param_2 = *param_2 | 0x20;
      fVar1 = *(float *)(param_1 + 4);
      if (local_5c <= *(float *)(param_1 + 4)) {
        fVar1 = local_5c;
      }
      *(float *)(param_1 + 4) = fVar1;
      fVar1 = *(float *)(param_1 + 8);
      if (*(float *)(param_1 + 8) <= local_58) {
        fVar1 = local_58;
      }
      *(float *)(param_1 + 8) = fVar1;
      uVar3 = FUN_1001eaa0(*(undefined4 **)(param_1 + 0xc),local_54);
      *(undefined4 *)(param_1 + 0xc) = uVar3;
      return iVar4;
    }
  }
  else {
    FUN_1000cba0(0x65);
  }
  return 0;
}


