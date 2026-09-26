// 0040f631 FUN_0040f631 [Global]
// programa: sfmain.exe

void __fastcall FUN_0040f631(undefined4 param_1)

{
  int iVar1;
  int in_EAX;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  int local_2c;
  int local_28;
  int local_24;
  
  local_24 = 0;
  iVar1 = *(int *)(in_EAX + 0x14);
  if (DAT_00449c1d == 0) {
    DAT_00449c1d = 1;
    for (local_2c = 0; local_2c < iVar1; local_2c = local_2c + 0xa0) {
      for (local_28 = 0; local_28 < 0xa0; local_28 = local_28 + 1) {
        if (local_2c + local_28 < *(int *)(in_EAX + 0x14)) {
          *(undefined2 *)(&DAT_00449abc + local_28 * 2) =
               *(undefined2 *)
                (&DAT_00426f92 + (uint)*(byte *)(local_2c + local_28 + in_EAX + 0x1c) * 2);
        }
        else {
          *(undefined2 *)(&DAT_00449abc + local_28 * 2) = 0;
        }
      }
      FUN_00406bbd(param_1,(short *)&DAT_00449abc);
      FUN_004080a4(extraout_ECX,&DAT_00449bfc);
      local_24 = local_24 + 0x21;
      param_1 = extraout_ECX_00;
    }
    *(short *)(in_EAX + 0x1c) = (short)iVar1;
    FUN_00429618();
    *(int *)(in_EAX + 0x14) = local_24 + 2;
    DAT_00449c1d = 0;
  }
  else {
    FUN_004296b9(s_Tried_to_re_enter_gsmcomp__00435b98);
    *(undefined2 *)(in_EAX + 0x1c) = 0;
    *(undefined4 *)(in_EAX + 0x14) = 2;
  }
  return;
}


