// 10021160 RwCreateUserRaster [Global]
// programa: RWL21.DLL

undefined4 *
RwCreateUserRaster(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int iVar3;
  
                    /* 0x21160  50  RwCreateUserRaster */
  uVar1 = *(undefined4 *)(PTR_DAT_1005b69c + 0x14);
  puVar2 = FUN_10037030(DAT_1005acdc);
  if (puVar2 == (undefined4 *)0x0) {
    FUN_1000cba0(3);
    puVar2 = (undefined4 *)0x0;
  }
  else {
    puVar2[0xc] = 0;
    puVar2[0xf] = 0;
    puVar2[0xd] = 0;
    puVar2[0xe] = 0;
    puVar2[7] = 0;
    puVar2[8] = 0;
    puVar2[9] = uVar1;
    puVar2[1] = 0;
    iVar3 = (**(code **)(PTR_DAT_1005b69c + 0x2a0))(puVar2);
    if (iVar3 == 0) {
      FUN_10037010(DAT_1005acdc,puVar2);
      puVar2 = (undefined4 *)0x0;
    }
  }
  if (puVar2 != (undefined4 *)0x0) {
    puVar2[7] = param_1;
    puVar2[8] = param_2;
    puVar2[10] = param_3;
    puVar2[6] = param_4;
    puVar2[0x10] = puVar2[0x10] | 0xc;
    return puVar2;
  }
  return (undefined4 *)0x0;
}


