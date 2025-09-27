#include <iostream>

int SomeFunc(
    int a,
    int b,
    int c,
    int d,
    int e,
    int f,
    int g,
    int h,
    int i,
    int j,
    int k,
    int l,
    int m,
    int n,
    int o,
    int p,
    int q,
    int r,
    int s,
    int t,
    int u,
    int v,
    int w,
    int x,
    int y,
    int z,

    int aa,
    int ab,
    int ac,
    int ad,
    int ae,
    int af,
    int ag,
    int ah,
    int ai,
    int aj,
    int ak,
    int al,
    int am,
    int an,
    int ao,
    int ap,
    int aq,
    int ar,
    int as,
    int at,
    int au,
    int av,
    int aw,
    int ax,
    int ay,
    int az
) {
    std::cout << "Heavy math!: " << k << std::endl;
    std::cout << "Heavy math!: " << (j + h) << std::endl;
    std::cout << "Heavy math!: " << (g * h) << std::endl;

    return
        a -
        b /
        c *
        d /
        e +
        f -
        g *
        h *
        i /
        j +
        k -
        l *
        m *
        n -
        o +
        p /
        q *
        r +
        s /
        t *
        u -
        v -
        w /
        x *
        y +
        z *

        aa -
        ab /
        ac *
        ad /
        ae +
        af -
        ag *
        ah *
        ai /
        aj +
        ak -
        al *
        am *
        an -
        ao +
        ap /
        aq *
        ar +
        as /
        at *
        au -
        av -
        aw /
        ax *
        ay +
        az;
}

void foo(float* a, float* b, int n) {
    for (int i = 0; i < n; ++i)
        a[i] = b[i] * 2.0f;
}

int main() {

    float *fa = new float[8000];
    float *fb = new float[8000];
    foo(fa, fb, 1000);
    delete [] fa;
    delete [] fb;

    int a = 1;
    int b = 35;
    int c = 53;
    int d = 346;
    int e = 35;
    int f = 578;
    int g = 84;
    int h = 26;
    int i = 37;
    int j = 48;
    int k = 65;
    int l = 38;
    int m = 23;
    int n = 162;
    int o = 132;
    int p = 92;
    int q = 45652;
    int r = 1345;
    int s = 1537;
    int t = 184;
    int u = 1972;
    int v = 154568;
    int w = 2345;
    int x = 345;
    int y = 51;
    int z = 122;

    int aa = 1;
    int ab = 35;
    int ac = 53;
    int ad = 346;
    int ae = 35;
    int af = 578;
    int ag = 84;
    int ah = 26;
    int ai = 37;
    int aj = 48;
    int ak = 65;
    int al = 38;
    int am = 23;
    int an = 162;
    int ao = 132;
    int ap = 92;
    int aq = 45652;
    int ar = 1345;
    int as = 1537;
    int at = 184;
    int au = 1972;
    int av = 154568;
    int aw = 2345;
    int ax = 345;
    int ay = 51;
    int az = 122;

    SomeFunc(
        a,
        b,
        c,
        d,
        e,
        f,
        g,
        h,
        i,
        j,
        k,
        l,
        m,
        n,
        o,
        p,
        q,
        r,
        s,
        t,
        u,
        v,
        w,
        x,
        y,
        z,

        aa,
        ab,
        ac,
        ad,
        ae,
        af,
        ag,
        ah,
        ai,
        aj,
        ak,
        al,
        am,
        an,
        ao,
        ap,
        aq,
        ar,
        as,
        at,
        au,
        av,
        aw,
        ax,
        ay,
        az
    );

    return 0;
}
