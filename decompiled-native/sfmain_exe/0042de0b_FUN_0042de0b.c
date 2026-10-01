// 0042de0b FUN_0042de0b [Global]
// program: sfmain.exe

unkbyte10 FUN_0042de0b(void)

{
  unkbyte10 in_ST0;
  unkbyte10 extraout_ST0;
  unkbyte10 in_ST5;
  undefined2 uVar1;
  undefined2 uStack00000016;
  undefined4 in_stack_00000014;
  
  uStack00000016 = (undefined2)((uint)in_stack_00000014 >> 0x10);
  uVar1 = (undefined2)((unkuint10)in_ST0 >> 0x40);
  FUN_0042da44((int)in_ST5,(uint)((unkuint10)in_ST5 >> 0x20),(ushort)((unkuint10)in_ST5 >> 0x40),
               (int)in_ST0,(uint)((unkuint10)in_ST0 >> 0x20),CONCAT22(uStack00000016,uVar1));
  return extraout_ST0;
}


