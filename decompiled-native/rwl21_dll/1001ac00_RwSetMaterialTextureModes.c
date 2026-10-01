// 1001ac00 RwSetMaterialTextureModes [Global]
// program: RWL21.DLL

int RwSetMaterialTextureModes(int param_1,uint param_2)

{
  byte bVar1;
  
                    /* 0x1ac00  426  RwSetMaterialTextureModes */
  if ((param_2 & 0xffffffe8) != 0) {
    FUN_1000cba0(0x39);
    return 0;
  }
  if (param_1 != 0) {
    bVar1 = *(byte *)(param_1 + 0x30) & 0xe8;
    *(byte *)(param_1 + 0x30) = bVar1;
    *(byte *)(param_1 + 0x30) = (byte)param_2 | bVar1;
    return param_1;
  }
  FUN_1000cba0(1);
  return 0;
}


