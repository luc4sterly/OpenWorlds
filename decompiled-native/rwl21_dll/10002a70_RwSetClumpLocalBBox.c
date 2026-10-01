// 10002a70 RwSetClumpLocalBBox [Global]
// program: RWL21.DLL

int RwSetClumpLocalBBox(int param_1,float *param_2,float *param_3)

{
  undefined4 *puVar1;
  uint uVar2;
  float local_74;
  float local_70;
  float local_6c;
  
                    /* 0x2a70  387  RwSetClumpLocalBBox */
  uVar2 = 0;
  puVar1 = (undefined4 *)(*(int *)(param_1 + 0x88) + 0xc);
  do {
    *puVar1 = 0xff7fffff;
    if ((uVar2 & 1) == 0) {
      *puVar1 = 0x7f7fffff;
    }
    puVar1[1] = 0x7f7fffff;
    if ((uVar2 & 2) == 0) {
      puVar1[1] = 0xff7fffff;
    }
    puVar1[2] = 0x7f7fffff;
    if ((uVar2 & 4) == 0) {
      puVar1[2] = 0xff7fffff;
    }
    puVar1 = puVar1 + 0x1d;
    uVar2 = uVar2 + 1;
  } while ((int)uVar2 < 8);
  local_74 = *param_2;
  local_70 = param_2[1];
  local_6c = param_2[2];
  FUN_100421e0(*(int *)(param_1 + 0x88),&local_74);
  local_74 = *param_3;
  local_70 = param_3[1];
  local_6c = param_3[2];
  FUN_100421e0(*(int *)(param_1 + 0x88),&local_74);
  return param_1;
}


