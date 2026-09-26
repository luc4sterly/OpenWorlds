// 1000b9b0 FUN_1000b9b0 [Global]
// programa: RWDL8D21.DLL

int FUN_1000b9b0(int param_1,int param_2,byte *param_3)

{
  return ((uint)param_3[2] * 2 -
         (int)(short)((ushort)(byte)(&DAT_100781d0)[*(byte *)((int)&DAT_10077db0 + param_2)] +
                     (ushort)(byte)(&DAT_100781d0)[*(byte *)((int)&DAT_10077db0 + param_1)])) *
         (int)(short)((ushort)(byte)(&DAT_100781d0)[*(byte *)((int)&DAT_10077db0 + param_1)] -
                     (ushort)(byte)(&DAT_100781d0)[*(byte *)((int)&DAT_10077db0 + param_2)]) +
         ((uint)param_3[1] * 2 -
         (int)(short)((ushort)(byte)(&DAT_100781d0)[*(byte *)((int)&DAT_10077fc0 + param_2)] +
                     (ushort)(byte)(&DAT_100781d0)[*(byte *)((int)&DAT_10077fc0 + param_1)])) *
         (int)(short)((ushort)(byte)(&DAT_100781d0)[*(byte *)((int)&DAT_10077fc0 + param_1)] -
                     (ushort)(byte)(&DAT_100781d0)[*(byte *)((int)&DAT_10077fc0 + param_2)]) +
         ((uint)*param_3 * 2 -
         (int)(short)((ushort)(byte)(&DAT_100781d0)[*(byte *)((int)&DAT_10077ec0 + param_2)] +
                     (ushort)(byte)(&DAT_100781d0)[*(byte *)((int)&DAT_10077ec0 + param_1)])) *
         (int)(short)((ushort)(byte)(&DAT_100781d0)[*(byte *)((int)&DAT_10077ec0 + param_1)] -
                     (ushort)(byte)(&DAT_100781d0)[*(byte *)((int)&DAT_10077ec0 + param_2)]);
}


