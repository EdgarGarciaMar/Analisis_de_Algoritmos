<script>

// A JavaScript program to find minimum possible
// time by the car chassis to complete

const NUM_LINE = 2;
const NUM_STATION = 4;

// Utility function to find a minimum of two numbers
function min(a, b)
{
	return a < b ? a : b;
}

function carAssembly(a, t, e, x)
{
	let T1 = new Array(NUM_STATION);
	let T2 = new Array(NUM_STATION);
	let i;

	// time taken to leave first station in line 1
	T1[0] = e[0] + a[0][0];
	
	// time taken to leave first station in line 2
	T2[0] = e[1] + a[1][0];

	// Fill tables T1[] and T2[] using the
	// above given recursive relations
	for (i = 1; i < NUM_STATION; ++i)
	{
		T1[i] = min(T1[i - 1] + a[0][i],
					T2[i - 1] + t[1][i] + a[0][i]);
		T2[i] = min(T2[i - 1] + a[1][i],
					T1[i - 1] + t[0][i] + a[1][i]);
	}

	// Consider exit times and retutn minimum
	return min(T1[NUM_STATION - 1] + x[0],
			T2[NUM_STATION - 1] + x[1]);
}

// Driver Code
	let a = [[4, 5, 3, 2],
							[2, 10, 1, 4]];
	let t = [[0, 7, 4, 5],
							[0, 9, 2, 8]];
	let e = [10, 12], x = [18, 7];

	document.write(carAssembly(a, t, e, x));


// This code is contributed by Surbhi Tyagi.

</script>
