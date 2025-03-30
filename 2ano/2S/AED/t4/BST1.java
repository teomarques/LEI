package DataStructures;
import Supporting.*;
import Exceptions.*;
import Supporting.Comparable;

// @author Mark Allen Weiss
public class BinarySearchTree
implements SearchTree
{
public BinarySearchTree( )
{ root = null; }
public void insert( Comparable x )
throws DuplicateItem
{ root = insert( x, root ); }
public void remove( Comparable x )
throws ItemNotFound
{ root = remove( x, root ); }
public void removeMin( )
throws ItemNotFound
{ root = removeMin( root ); }

public Comparable findMin( ) throws ItemNotFound
{ return findMin( root ).element; }
public Comparable findMax( ) throws ItemNotFound
{ return findMax( root ).element; }
public Comparable find( Comparable x )
throws ItemNotFound
{ return find( x, root ).element ; }
public void makeEmpty( )
{ root = null; }
public boolean isEmpty( )
{ return root == null; }
public void printTree( )
{
if( root == null )
System.out.println( "Empty tree" );
else
printTree( root );
}

protected BinaryNode insert( Comparable x, BinaryNode t ) throws DuplicateItem
{ if( t == null )
t = new BinaryNode( x, null, null );
else if( x.compares( t .element ) < 0 )
t.left = insert( x, t.left );
else if( x.compares( t.element ) > 0 )
t.right = insert( x, t.right );
else
throw new DuplicateItem( "SearchTree insert" );
return t; }
protected BinaryNode remove( Comparable x, BinaryNode t ) throws ItemNotFound
{ if( t == null )
throw new ItemNotFound( "SearchTree remove" );
if( x.compares( t.element ) < 0 )
t.left = remove( x, t.left );
else if( x.compares( t.element ) > 0 )
t.right = remove( x, t.right );
else if( t.left != null && t.right != null ) // Two children
{
t.element = findMin( t.right ).element;
t.right = removeMin( t.right );
}
else
t = ( t.left != null ) ? t.left : t.right;
return t; }

protected BinaryNode removeMin( BinaryNode t ) throws ItemNotFound
{ if( t == null )
throw new ItemNotFound( "SearchTree removeMin" );
if( t.left != null )
t.left = removeMin( t.left );
else
t = t.right;
return t;
}
protected BinaryNode findMin( BinaryNode t ) throws ItemNotFound
{ if( t == null )
throw new ItemNotFound( "SearchTree findMin" );
while( t.left != null )
t = t.left;
return t;
}
protected BinaryNode findMax( BinaryNode t ) throws ItemNotFound
{ if( t == null )
throw new ItemNotFound( "SearchTree findMax" );
while( t.right != null )
t = t.right;
return t;
}

protected BinaryNode find( Comparable x, BinaryNode t ) throws ItemNotFound
{ while( t != null )
if( x.compares( t.element ) < 0 )
t = t.left;
else if( x.compares( t.element ) > 0 )
t = t.right;
else
return t; // Match
throw new ItemNotFound( "SearchTree find" );
}
protected void printTree( BinaryNode t )
{ if( t != null )
{ printTree( t.left );
System.out.println( t.element.toString( ) );
printTree( t.right );
}
}
/** The tree root. */
protected BinaryNode root;
}
