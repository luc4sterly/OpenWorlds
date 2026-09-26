// 0042dd87 FUN_0042dd87 [Global]
// programa: sfmain.exe

unkbyte10 FUN_0042dd87(void)

{
  code *pcVar1;
  unkbyte10 Var2;
  unkbyte10 extraout_ST0;
  unkbyte10 in_ST4;
  undefined2 uVar3;
  undefined2 uStack00000046;
  undefined4 in_stack_00000044;
  
  uStack00000046 = (undefined2)((uint)in_stack_00000044 >> 0x10);
  pcVar1 = (code *)swi(6);
  Var2 = (*pcVar1)();
  uVar3 = (undefined2)((unkuint10)in_ST4 >> 0x40);
  FUN_0042da44((int)Var2,(uint)((unkuint10)Var2 >> 0x20),(ushort)((unkuint10)Var2 >> 0x40),
               (int)in_ST4,(uint)((unkuint10)in_ST4 >> 0x20),CONCAT22(uStack00000046,uVar3));
  return extraout_ST0;
}


