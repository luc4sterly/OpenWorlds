// 100029d0 RwSetupImmediateLine [Global]
// programa: RWL21.DLL

void RwSetupImmediateLine(undefined4 *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  
                    /* 0x29d0  488  RwSetupImmediateLine */
  *param_1 = 0;
  param_1[1] = 0;
  iVar2 = 2;
  param_1[0x59] = 0;
  param_1[0x5a] = 0;
  param_1[0x5b] = 0;
  param_1[0x5c] = 0;
  *(undefined1 *)((int)param_1 + 0x19e) = 2;
  puVar1 = param_1 + 2;
  do {
    *puVar1 = 0;
    iVar2 = iVar2 + -1;
    puVar1[1] = 0;
    puVar1[2] = 0;
    puVar1[6] = 0;
    puVar1[7] = 0;
    puVar1[0x16] = 0;
    puVar1[0x17] = 0;
    puVar1[0x18] = 0;
    puVar1 = puVar1 + 0x1d;
  } while (iVar2 != 0);
  return;
}


