void cond_swap(int &x, int &y) {
	bool r = x < y;
	int temp = r ? x : y;
	y = r ? y : x;
	x = temp;
}

void partially_sorted_swap(int &x, int &y, int &z) {
	bool r = z < x;
	int temp = r ? z : x;
	z = r ? x : z;
	r = temp < y;
	x = r ? x : y;
	y = r ? y : temp;
}

void Sort3(int *buffer) {
	int a = buffer[0], b = buffer[1], c = buffer[2];
	cond_swap(b, c);
	partially_sorted_swap(a, b, c);
	buffer[0] = a; buffer[1] = b; buffer[2] = c;
}

void Sort4(int *buffer) {
	int a = buffer[0], b = buffer[1], c = buffer[2], d = buffer[3];
	cond_swap(a, c);
	cond_swap(b, d);
	cond_swap(a, b);
	cond_swap(c, d);
	cond_swap(b, c);
	buffer[0] = a; buffer[1] = b; buffer[2] = c; buffer[3] = d;
}

void Sort5(int *buffer) {
	int a = buffer[0], b = buffer[1], c = buffer[2], d = buffer[3], e = buffer[4];
	cond_swap(a, b);
	cond_swap(d, e);
	partially_sorted_swap(c, d, e);
	cond_swap(b, e);
	partially_sorted_swap(a, c, d);
	partially_sorted_swap(b, c, d);
	buffer[0] = a; buffer[1] = b; buffer[2] = c; buffer[3] = d; buffer[4] = e;
}

void Sort6(int *buffer) {
	int a = buffer[0], b = buffer[1], c = buffer[2];
	int d = buffer[3], e = buffer[4], f = buffer[5];

	cond_swap(b, c);
	partially_sorted_swap(a, b, c);

	cond_swap(e, f);
	partially_sorted_swap(d, e, f);

	cond_swap(c, f);
	cond_swap(a, d);
	cond_swap(b, e);
	cond_swap(b, d);
	cond_swap(c, d);
	cond_swap(d, e);

	buffer[0] = a; buffer[1] = b; buffer[2] = c;
	buffer[3] = d; buffer[4] = e; buffer[5] = f;
}

void Sort7(int *buffer) {
	int a = buffer[0], b = buffer[1], c = buffer[2];
	int d = buffer[3], e = buffer[4], f = buffer[5], g = buffer[6];

	cond_swap(b, c);
	cond_swap(a, c);

	cond_swap(d, e);
	cond_swap(f, g);
	cond_swap(d, f);
	cond_swap(e, g);

	cond_swap(c, g);
	cond_swap(b, f);
	cond_swap(a, e);
	cond_swap(c, f);

	cond_swap(b, d);
	cond_swap(c, e);
	partially_sorted_swap(a, b, d);
	cond_swap(c, d);
	cond_swap(e, f);

	buffer[0] = a; buffer[1] = b; buffer[2] = c;
	buffer[3] = d; buffer[4] = e; buffer[5] = f;
	buffer[6] = g;
}

void Sort8(int *buffer) {
	int a = buffer[0], b = buffer[1], c = buffer[2], d = buffer[3];
	int e = buffer[4], f = buffer[5], g = buffer[6], h = buffer[7];

	cond_swap(a, c);
	cond_swap(b, d);
	cond_swap(a, b);
	cond_swap(c, d);
	cond_swap(b, c);

	cond_swap(e, g);
	cond_swap(f, h);
	cond_swap(e, f);
	cond_swap(g, h);
	cond_swap(f, g);

	cond_swap(a, e);
	cond_swap(b, f);
	cond_swap(c, g);
	cond_swap(d, h);
	cond_swap(c, e);
	cond_swap(d, f);
	cond_swap(b, c);
	cond_swap(d, e);
	cond_swap(f, g);

	buffer[0] = a; buffer[1] = b; buffer[2] = c; buffer[3] = d;
	buffer[4] = e; buffer[5] = f; buffer[6] = g; buffer[7] = h;
}

void VarSort3(int *buffer) {
	int n = buffer[0];
	if (n < 2) return;
	if (n < 3) { cond_swap(buffer[1], buffer[2]); return; }
	Sort3(buffer + 1);
}

void VarSort4(int *buffer) {
	if (buffer[0] < 4) { VarSort3(buffer); return; }
	Sort4(buffer + 1);
}

void VarSort5(int *buffer) {
	if (buffer[0] < 5) { VarSort4(buffer); return; }
	Sort5(buffer + 1);
}
