// 004262fe FUN_004262fe [Global]
// program: sfmain.exe

void FUN_004262fe(void)

{
  int in_EAX;
  undefined4 extraout_ECX;
  undefined1 *puVar1;
  short local_1c;
  undefined1 local_1a;
  
  puVar1 = (undefined1 *)(in_EAX + *(int *)(in_EAX + 0x14) + 0x19);
  local_1c = CONCAT11(*puVar1,puVar1[1]);
  local_1a = puVar1[2];
  *(int *)(in_EAX + 0x14) = *(int *)(in_EAX + 0x14) + -3;
  FUN_00401170(&local_1c,(undefined1 *)0x4b6d00);
  *(int *)(in_EAX + 0x14) = *(int *)(in_EAX + 0x14) << 1;
  FUN_004080a4(extraout_ECX,(undefined1 *)0x4b6d00);
  return;
}


