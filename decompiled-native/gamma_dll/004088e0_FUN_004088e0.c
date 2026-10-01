// 004088e0 FUN_004088e0 [Global]
// program: gamma.dll

undefined4 __fastcall FUN_004088e0(int *param_1)

{
  uint *puVar1;
  uint *puVar2;
  uint *puVar3;
  void *local_50;
  uint *local_4c;
  undefined1 *local_34;
  undefined1 *local_1c;
  undefined4 local_18;
  uint local_14;
  
  if (1 < ((uint *)*param_1)[2]) {
    local_14 = *(uint *)*param_1;
    puVar1 = (uint *)*param_1;
    FUN_00406470(&local_18,puVar1 + 4);
    if (puVar1[2] < 2) {
      FUN_00404f40(&local_18);
      puVar2 = puVar1;
    }
    else {
      puVar2 = (uint *)FUN_00406450(1);
      local_1c = (undefined1 *)&local_50;
      local_4c = puVar2;
      local_50 = (void *)FUN_00406440(0x28,puVar2);
      if (local_50 != (void *)0x0) {
        local_34 = (undefined1 *)&local_50;
        FUN_004063e0(local_50,puVar1 + 1,local_14);
      }
      puVar1[2] = puVar1[2] - 1;
      puVar3 = FUN_004063b0(&local_14,puVar1);
      FUN_00406390((undefined4 *)puVar2[3],(undefined4 *)puVar1[3],*puVar3 + 1);
      *puVar2 = *puVar1;
      FUN_00404f40(&local_18);
    }
    *param_1 = (int)puVar2;
  }
  *(undefined4 *)(*param_1 + 8) = 0;
  return *(undefined4 *)(*param_1 + 0xc);
}


