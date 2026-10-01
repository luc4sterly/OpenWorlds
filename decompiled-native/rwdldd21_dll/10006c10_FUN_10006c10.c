// 10006c10 FUN_10006c10 [Global]
// program: RWDLDD21.DLL

uint * FUN_10006c10(uint *param_1)

{
  uint *puVar1;
  
  if (param_1 == (uint *)0x0) {
    return (uint *)0x0;
  }
  puVar1 = (uint *)(**(code **)(DAT_100394fc + 0x34c))(4);
  if (puVar1 == (uint *)0x0) {
    return (uint *)0x0;
  }
  *puVar1 = (uint)CONCAT11(*(undefined1 *)((int)param_1 + 5),*(undefined1 *)((int)param_1 + 9)) |
            (*param_1 & 0xffffff00 | 0xffff0000) << 8;
  return puVar1;
}


