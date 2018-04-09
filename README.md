# QuasiRegularRigidMotion

To install the program see <a href="https://github.com/ngophuc/QuasiRegularRigidMotion/blob/master/INSTALL.txt">INSTALL.txt</a> file


If you want you can also directly test the programm online:

http://ipol-geometry.loria.fr/~phuc/ipol_demo/RigidMotion2D/


* [![Build Status](https://travis-ci.org/ngophuc/QuasiRegularRigidMotion.svg?branch=master)](https://travis-ci.org/ngophuc/QuasiRegularRigidMotion)

# Examples

<p>File <a href="https://github.com/ngophuc/QuasiRegularRigidMotion/blob/master/Samples/circle10.pgm">circle10.pgm</a>: </p>&#x000A;&#x000A;
<pre class="code highlight js-syntax-highlight plaintext">
<code>./testRigidTransform -i ../Samples/circle10.pgm -o ../Results/circle10 -e -a 0.1 -b 0.2 -t 0.23</code>
</pre>&#x000A;&#x000A;
<p>
	<table cellpadding="5">
		<tr>
		<td align="center" valign="center">
			<a href="https://github.com/ngophuc/QuasiRegularRigidMotion/blob/master/Samples/circle10.png">
				<img width="150" src="https://github.com/ngophuc/QuasiRegularRigidMotion/blob/master/Samples/circle10.png" alt="Input image" />
			</a>	
		<br />
		Input image
		</td>		
		<td align="center" valign="center">
			<a href="https://github.com/ngophuc/QuasiRegularRigidMotion/blob/master/Results/circle10_points.eps">
				<img width="120" src="https://github.com/ngophuc/QuasiRegularRigidMotion/blob/master/Results/circle10_points.png" alt="Input points" />
			</a>	
		<br />
		Input points
		</td>
		<td align="center" valign="center">
			<a href="https://github.com/ngophuc/QuasiRegularRigidMotion/blob/master/Results/circle10_tpoint.eps">
				<img width="100" src="https://github.com/ngophuc/QuasiRegularRigidMotion/blob/master/Results/circle10_tpoint.png" alt="T_point" />
			</a>
		<br />
		Rigid motion point-by-point
		</td>
    		<td align="center" valign="center">
			<a href="https://github.com/ngophuc/QuasiRegularRigidMotion/blob/master/Results/circle10_thull.eps">
				<img width="90" src="https://github.com/ngophuc/QuasiRegularRigidMotion/blob/master/Results/circle10_thull.png" alt="T_hull" />
			</a>
		<br />
		Rigid motion by convex hull
		</td>  
		<td align="center" valign="center">
			<a href="https://github.com/ngophuc/QuasiRegularRigidMotion/blob/master/Results/circle10_tpoly.pdf">
				<img width="90" src="https://github.com/ngophuc/QuasiRegularRigidMotion/blob/master/Results/circle10_tpoly.png" alt="T_poly" />
			</a>
		<br />
		Rigid motion by polygonalization
		</td>  	
		</tr>
	</table>
</p>

<p>File <a href="https://github.com/ngophuc/QuasiRegularRigidMotion/blob/master/Samples/square21.pgm">square21.pgm</a>: </p>&#x000A;&#x000A;
<pre class="code highlight js-syntax-highlight plaintext">
<code>./testRigidTransform -i ../Samples/square21.pgm -o ../Results/square21 -e -a 0.0 -b 0.0 -t 0.23</code>
</pre>&#x000A;&#x000A;
<p>
	<table cellpadding="5">
		<tr>
		<td align="center" valign="center">
			<a href="https://github.com/ngophuc/QuasiRegularRigidMotion/blob/master/Samples/square21.png">
				<img width="150" src="https://github.com/ngophuc/QuasiRegularRigidMotion/blob/master/Samples/square21.png" alt="Input image" />
			</a>	
		<br />
		Input image
		</td>		
		<td align="center" valign="center">
			<a href="https://github.com/ngophuc/QuasiRegularRigidMotion/blob/master/Results/square21_points.eps">
				<img width="100" src="https://github.com/ngophuc/QuasiRegularRigidMotion/blob/master/Results/square21_points.png" alt="Input points" />
			</a>	
		<br />
		Input points
		</td>
		<td align="center" valign="center">
			<a href="https://github.com/ngophuc/QuasiRegularRigidMotion/blob/master/Results/square21_tpoint.eps">
				<img width="100" src="https://github.com/ngophuc/QuasiRegularRigidMotion/blob/master/Results/square21_tpoint.png" alt="T_point" />
			</a>
		<br />
		Rigid motion point-by-point
		</td>
    		<td align="center" valign="center">
			<a href="https://github.com/ngophuc/QuasiRegularRigidMotion/blob/master/Results/square21_thull.eps">
				<img width="90" src="https://github.com/ngophuc/QuasiRegularRigidMotion/blob/master/Results/square21_thull.png" alt="T_hull" />
			</a>
		<br />
		Rigid motion by convex hull
		</td>  
		<td align="center" valign="center">
			<a href="https://github.com/ngophuc/QuasiRegularRigidMotion/blob/master/Results/square21_tpoly.eps">
				<img width="90" src="https://github.com/ngophuc/QuasiRegularRigidMotion/blob/master/Results/square21_tpoly.png" alt="T_poly" />
			</a>
		<br />
		Rigid motion by polygonalization
		</td>  	
		</tr>
	</table>
</p>

<p>File <a href="https://github.com/ngophuc/QuasiRegularRigidMotion/blob/master/Samples/flower.pgm">flower.pgm</a>: </p>&#x000A;&#x000A;
<pre class="code highlight js-syntax-highlight plaintext">
<code>./testRigidTransform -i ../Samples/flower.pgm -o ../Results/flower -e -a 0.1 -b 0.3 -t 0.314</code>
</pre>&#x000A;&#x000A;
<p>
	<table cellpadding="5">
		<tr>
		<td align="center" valign="center">
			<a href="https://github.com/ngophuc/QuasiRegularRigidMotion/blob/master/Samples/flower.png">
				<img width="150" src="https://github.com/ngophuc/QuasiRegularRigidMotion/blob/master/Samples/flower.png" alt="Input image" />
			</a>	
		<br />
		Input image
		</td>		
		<td align="center" valign="center">
			<a href="https://github.com/ngophuc/QuasiRegularRigidMotion/blob/master/Results/flower_points.eps">
				<img width="120" src="https://github.com/ngophuc/QuasiRegularRigidMotion/blob/master/Results/flower_points.png" alt="Input points" />
			</a>	
		<br />
		Input points
		</td>
		<td align="center" valign="center">
			<a href="https://github.com/ngophuc/QuasiRegularRigidMotion/blob/master/Results/flower_tpoint.eps">
				<img width="100" src="https://github.com/ngophuc/QuasiRegularRigidMotion/blob/master/Results/flower_tpoint.png" alt="T_point" />
			</a>
		<br />
		Rigid motion point-by-point
		</td>
    		<td align="center" valign="center">
			<a href="https://github.com/ngophuc/QuasiRegularRigidMotion/blob/master/Results/flower_thull.eps">
				<img width="100" src="https://github.com/ngophuc/QuasiRegularRigidMotion/blob/master/Results/flower_thull.png" alt="T_hull" />
			</a>
		<br />
		Rigid motion by convex hull
		</td>  
		<td align="center" valign="center">
			<a href="https://github.com/ngophuc/QuasiRegularRigidMotion/blob/master/Results/flower_tpoly.eps">
				<img width="100" src="https://github.com/ngophuc/QuasiRegularRigidMotion/blob/master/Results/flower_tpoly.png" alt="T_poly" />
			</a>
		<br />
		Rigid motion by polygonalization
		</td>  	
		</tr>
	</table>
</p>

<p>File <a href="https://github.com/ngophuc/QuasiRegularRigidMotion/blob/master/Samples/leaf.pgm">leaf.pgm</a>: </p>&#x000A;&#x000A;
<pre class="code highlight js-syntax-highlight plaintext">
<code>./testRigidTransform -i ../Samples/leaf.pgm -o ../Results/leaf -e -a 0.1 -b 0.1 -t 0.314</code>
</pre>&#x000A;&#x000A;
<p>
	<table cellpadding="5">
		<tr>
		<td align="center" valign="center">
			<a href="https://github.com/ngophuc/QuasiRegularRigidMotion/blob/master/Samples/leaf.png">
				<img width="150" src="https://github.com/ngophuc/QuasiRegularRigidMotion/blob/master/Samples/leaf.png" alt="Input image" />
			</a>	
		<br />
		Input image
		</td>		
		<td align="center" valign="center">
			<a href="https://github.com/ngophuc/QuasiRegularRigidMotion/blob/master/Results/leaf_points.eps">
				<img width="110" src="https://github.com/ngophuc/QuasiRegularRigidMotion/blob/master/Results/leaf_points.png" alt="Input points" />
			</a>	
		<br />
		Input points
		</td>
		<td align="center" valign="center">
			<a href="https://github.com/ngophuc/QuasiRegularRigidMotion/blob/master/Results/leaf_tpoint.eps">
				<img width="100" src="https://github.com/ngophuc/QuasiRegularRigidMotion/blob/master/Results/leaf_tpoint.png" alt="T_point" />
			</a>
		<br />
		Rigid motion point-by-point
		</td>
    		<td align="center" valign="center">
			<a href="https://github.com/ngophuc/QuasiRegularRigidMotion/blob/master/Results/leaf_thull.eps">
				<img width="100" src="https://github.com/ngophuc/QuasiRegularRigidMotion/blob/master/Results/leaf_thull.png" alt="T_hull" />
			</a>
		<br />
		Rigid motion by convex hull
		</td>  
		<td align="center" valign="center">
			<a href="https://github.com/ngophuc/QuasiRegularRigidMotion/blob/master/Results/leaf_tpoly.eps">
				<img width="100" src="https://github.com/ngophuc/QuasiRegularRigidMotion/blob/master/Results/leaf_tpoly.png" alt="T_poly" />
			</a>
		<br />
		Rigid motion by polygonalization
		</td>  	
		</tr>
	</table>
</p>

<p>File <a href="https://github.com/ngophuc/QuasiRegularRigidMotion/blob/master/Samples/snowflake.pgm">snowflake.pgm</a>: </p>&#x000A;&#x000A;
<pre class="code highlight js-syntax-highlight plaintext">
<code>./testRigidTransform -i ../Samples/snowflake.pgm -o ../Results/snowflake -e -a 0.2 -b 0.2 -t 0.314</code>
</pre>&#x000A;&#x000A;
<p>
	<table cellpadding="5">
		<tr>
		<td align="center" valign="center">
			<a href="https://github.com/ngophuc/QuasiRegularRigidMotion/blob/master/Samples/snowflake.png">
				<img width="150" src="https://github.com/ngophuc/QuasiRegularRigidMotion/blob/master/Samples/snowflake.png" alt="Input image" />
			</a>	
		<br />
		Input image
		</td>		
		<td align="center" valign="center">
			<a href="https://github.com/ngophuc/QuasiRegularRigidMotion/blob/master/Results/snowflake_points.eps">
				<img width="110" src="https://github.com/ngophuc/QuasiRegularRigidMotion/blob/master/Results/snowflake_points.png" alt="Input points" />
			</a>	
		<br />
		Input points
		</td>
		<td align="center" valign="center">
			<a href="https://github.com/ngophuc/QuasiRegularRigidMotion/blob/master/Results/snowflake_tpoint.eps">
				<img width="100" src="https://github.com/ngophuc/QuasiRegularRigidMotion/blob/master/Results/snowflake_tpoint.png" alt="T_point" />
			</a>
		<br />
		Rigid motion point-by-point
		</td>
    		<td align="center" valign="center">
			<a href="https://github.com/ngophuc/QuasiRegularRigidMotion/blob/master/Results/snowflake_thull.eps">
				<img width="100" src="https://github.com/ngophuc/QuasiRegularRigidMotion/blob/master/Results/snowflake_thull.png" alt="T_hull" />
			</a>
		<br />
		Rigid motion by convex hull
		</td>  
		<td align="center" valign="center">
			<a href="https://github.com/ngophuc/QuasiRegularRigidMotion/blob/master/Results/snowflake_tpoly.eps">
				<img width="100" src="https://github.com/ngophuc/QuasiRegularRigidMotion/blob/master/Results/snowflake_tpoly.png" alt="T_poly" />
			</a>
		<br />
		Rigid motion by polygonalization
		</td>  	
		</tr>
	</table>
</p>
