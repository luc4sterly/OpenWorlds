// 10033f70 FUN_10033f70 [Global]
// program: RWL21.DLL

void FUN_10033f70(undefined4 param_1,int param_2)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  
  puVar1 = (undefined1 *)FUN_100274d0();
  if (puVar1 == &LAB_10027460) {
    puVar1 = &LAB_10027460;
    puVar2 = &LAB_10027490;
  }
  else if (*(undefined1 **)(PTR_DAT_1005b69c + *(int *)(param_2 + 0xe0) * 4 + 0x54) == puVar1) {
    puVar2 = *(undefined1 **)(PTR_DAT_1005b69c + *(int *)(param_2 + 0xe0) * 4 + 0x154);
  }
  else {
    puVar1 = &LAB_10027460;
    puVar2 = &LAB_10027490;
  }
  FUN_10033fd0(puVar1,puVar2,param_2);
  return;
}


