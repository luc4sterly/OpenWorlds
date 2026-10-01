// 0042b7f4 FUN_0042b7f4 [Global]
// program: sfmain.exe

undefined4 FUN_0042b7f4(void)

{
  undefined2 in_AX;
  ushort in_FPUStatusWord;
  
  do {
  } while ((in_FPUStatusWord & 0x400) != 0);
  return CONCAT22(in_FPUStatusWord,in_AX);
}


