// 1000b590 FUN_1000b590 [Global]
// program: RWDL6D21.DLL

undefined4 FUN_1000b590(void)

{
  if (DAT_1007920c != 0) {
    DAT_1007920c = DAT_1007920c + -0x8000;
    (**(code **)(DAT_1007bda8 + 0x358))(DAT_1007920c);
    DAT_1007920c = 0;
  }
  return 1;
}


